/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __frpath_readlink.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:41:05 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/11 22:14:00 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__frpath.h"

t_lstatus	__do_readlink(t_loc *lc)
{
	if (lc->do_readlink)
	{
		lc->k = ft_readlink(lc->out, lc->stk, lc->p);
		if (!lc->k)
		{
			errno = ENOENT;
			return (RETNULL);
		}
		if ((size_t)lc->k == lc->p)
			return (__toolongl());
		if (lc->k == -1 && errno != EINVAL)
			return (RETNULL);
		if (lc->k > 0)
		{
			if (lc->stk[lc->k - 1] == '/')
				while (lc->stk[lc->p] == '/')
					++lc->p;
			lc->p -= lc->k;
			ft_memmove((void *)(lc->stk + lc->p),
				(const void *)lc->stk, lc->k);
			return (CONTINUE);
		}
	}
	return (DEFAULT);
}
