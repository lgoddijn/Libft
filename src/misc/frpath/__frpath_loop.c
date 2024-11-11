/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __frpath_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:46:11 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/11 22:54:57 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__frpath.h"

static __always_inline t_lstatus	__resolv_parent(t_loc *lc)
{
	if (lc->parent)
	{
		while (lc->q && lc->out[lc->q - 1] != '/')
			--lc->q;
		if (lc->q > 1 && (lc->q > 2 || lc->out[0] != '/'))
			--lc->q;
		lc->p += __slash_count(lc->stk + lc->p);
		return (CONTINUE);
	}
	if (lc->l0)
		lc->q += lc->l;
	lc->check_directory = lc->stk[lc->p];
	lc->p += __slash_count(lc->stk + lc->p);
	return (CONTINUE);
}

static __always_inline t_lstatus	__cpy_component(t_loc *lc)
{
	if (lc->l == 1 && lc->stk[lc->p] == '.')
	{
		lc->p += lc->l + __slash_count(lc->stk + lc->p + lc->l);
		return (CONTINUE);
	}
	if (lc->q && lc->out[lc->q - 1] != '/')
	{
		if (!lc->p)
			return (__toolongl());
		lc->stk[--lc->p] = '/';
		++lc->l;
	}
	if (lc->q + lc->l >= PATH_MAX)
		return (__toolongl());
	return (DEFAULT);
}

static __always_inline t_lstatus	__resolv_component(t_loc *lc)
{
	t_lstatus	status;

	status = __cpy_component(lc);
	if (status == CONTINUE)
		return (CONTINUE);
	else if (status == RETNULL)
		return (RETNULL);
	ft_memcpy((char *)lc->out + lc->q, (const char *)lc->stk + lc->p, lc->l);
	lc->out[lc->q + lc->l] = '\0';
	lc->p += lc->l;
	lc->parent = (lc->l0 == 2
			&& lc->stk[lc->p - 2] == '.'
			&& lc->stk[lc->p - 1] == '.');
	lc->do_readlink = !lc->parent;
	if (lc->parent)
	{
		if (lc->q <= 3 * lc->nparent)
		{
			++lc->nparent;
			lc->q += lc->l;
			lc->p += __slash_count(lc->stk + lc->p);
			return (CONTINUE);
		}
	}
	return (DEFAULT);
}

t_loc	*__do_loop(t_loc *lc)
{
	t_lstatus	status;

	while (1)
	{
		status = __do_absolute(lc);
		if (status == RETNULL)
			return (NULL);
		else if (status == CONTINUE)
			continue ;
		else if (status == BREAK)
			break ;
		status = __resolv_component(lc);
		if (status == CONTINUE)
			continue ;
		status = __do_readlink(lc);
		if (status == CONTINUE)
			continue ;
		else if (status == RETNULL)
			return (NULL);
		status = __resolv_parent(lc);
		if (status == CONTINUE)
			continue ;
	}
	return (lc);
}
