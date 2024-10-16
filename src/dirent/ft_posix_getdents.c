/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_posix_getdents.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 00:47:34 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/10/16 15:43:43 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_dirent.h"

ssize_t	ft_posix_getdents(int fd, void *buf, size_t len, int flags)
{
	if (flags)
		return (__syscall_r(-EOPNOTSUPP));
	if (len > INT_MAX)
		len = INT_MAX;
	return (__syscall3(__NR_getdents, fd, (long)buf, len));
}
