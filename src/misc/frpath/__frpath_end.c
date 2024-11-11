/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __frpath_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:04:17 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/11 23:04:19 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__frpath.h"

static __always_inline void	__resolv_parent_components(t_loc *lc)
{
	lc->l = ft_strlen(lc->stk);
	lc->p = 0;
	while (lc->nparent--)
	{
		while (lc->l > 1 && lc->stk[lc->l - 1] != '/')
			--lc->l;
		if (lc->l > 1)
			--lc->l;
		lc->p += 2;
		if (lc->p < lc->q)
			++lc->p;
	}
	if (lc->q - lc->p && lc->stk[lc->l - 1] != '/')
		lc->stk[lc->l++] = '/';
}

t_loc	*__finalize_stack(t_loc *lc)
{
	lc->out[lc->q] = '\0';
	if (lc->out[0] != '/')
	{
		if (!ft_getcwd(lc->stk, sizeof(lc->stk)))
			return (NULL);
		__resolv_parent_components(lc);
		if (lc->l + (lc->q - lc->p) + 1 >= PATH_MAX)
			return (__toolong());
		ft_memmove((void *)(lc->out + lc->l),
			(const void *)(lc->out + lc->p), lc->q - lc->p + 1);
		__memcpy_fallback((void *)lc->out, (const void *)lc->stk, lc->l);
		lc->q = lc->l + lc->q - lc->p;
	}
	return (lc);
}
