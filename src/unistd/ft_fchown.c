/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fchown.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:32:22 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/01/01 20:40:28 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

int	ft_fchown(int __fd, uid_t __uid, gid_t __gid)
{
	if (!__x86_64__)
		return (ARCH_FAIL);
	return ((int)__syscall(__NR_fchown, __fd, __uid, __gid));
}
