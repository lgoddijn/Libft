/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getgroups.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:05:34 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/01/01 17:07:12 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

int	ft_getgroups(int __count, gid_t __list[])
{
	if (!__x86_64__)
		return (ARCH_FAIL);
	return ((int)__syscall(
			__NR_getgroups,
			__count,
			(long)__list));
}
