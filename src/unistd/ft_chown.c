/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chown.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 15:59:00 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/01/01 20:39:14 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

int	ft_chown(const char *__path, uid_t __uid, gid_t __gid)
{
	if (!__x86_64__)
		return (ARCH_FAIL);
	return ((int)__syscall(__NR_chown, (long)__path, __uid, __gid));
}
