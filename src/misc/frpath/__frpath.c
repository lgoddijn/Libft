/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __frpath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:11:26 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/11 23:02:48 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__frpath.h"

static char	*__frpath(const char *__restrict__ path, char resolved[PATH_MAX])
{
	t_loc	lc;

	if (!__init(path, &lc))
		return (NULL);
	if (!__do_resolv_loop(&lc))
		return (NULL);
	if (!__finalize_stack(&lc))
		return (NULL);
	return (__memcpy_fallback(resolved, lc.out, lc.q + 1));
}

extern char	*frpath(const char *__restrict__ path, char resolved[PATH_MAX])
			__attribute__((weak, alias("__frpath")));
