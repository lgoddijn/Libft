/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __frpath_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:41:53 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/11 23:03:39 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__frpath.h"

t_loc	*__init(const char *__restrict__ path, t_loc *lc)
{
	lc->nparent = 0;
	lc->check_directory = 0;
	if (!path)
	{
		errno = EINVAL;
		return (NULL);
	}
	lc->l = ft_strnlen(path, sizeof(lc->stk));
	if (!lc->l)
	{
		errno = ENOENT;
		return (NULL);
	}
	if (lc->l >= PATH_MAX)
		return (__toolong());
	lc->p = sizeof(lc->stk) - lc->l - 1;
	lc->q = 0;
	ft_memcpy(lc->stk + lc->p, path, lc->l + 1);
	return (lc);
}
