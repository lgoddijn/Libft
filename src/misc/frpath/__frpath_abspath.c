/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __frpath_abspath.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:44:30 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/11 22:12:03 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__frpath.h"

t_lstatus	__do_absolute(t_loc *lc)
{
	if (lc->stk[lc->p] == '~')
	{
		errno = ENOENT;
		return (RETNULL);
	}
	if (lc->stk[lc->p] == '/')
	{
		lc->check_directory = 0;
		lc->nparent = 0;
		lc->q = 0;
		lc->out[lc->q++] = '/';
		++lc->p;
		if (lc->stk[lc->p] == '/' && lc->stk[lc->p + 1] != '/')
			lc->out[lc->q++] = '/';
		lc->p += __slash_count(lc->stk + lc->p);
		return (CONTINUE);
	}
	lc->l = ft_strcspn(lc->stk + lc->p, "/");
	lc->l0 = lc->l;
	if (!lc->l && !lc->check_directory)
		return (BREAK);
	return (DEFAULT);
}
