/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getgroups.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:05:34 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/14 19:13:20 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

int32_t	ft_getgroups(int32_t __count, gid_t __list[])
{
	if (!__x86_64__)
		return (ARCH_FAIL);
	return ((int32_t)__syscall(
			__NR_getgroups,
			__count,
			(int64_t)__list));
}
