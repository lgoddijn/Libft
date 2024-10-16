/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdopendir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 00:45:14 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/10/16 00:47:00 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_dirent.h"

DIR	*ft_fdopendir(int fd)
{
	DIR			*dir;
	struct stat	st;

	if (fstat(fd, &st) < 0)
		return (0);
	if (fcntl(fd, F_GETFL) & O_PATH)
	{
		errno = EBADF;
		return (0);
	}
	if (!S_ISDIR(st.st_mode))
	{
		errno = ENOTDIR;
		return (0);
	}
	dir = (DIR *)ft_calloc(1, sizeof(*dir));
	if (!dir)
		return (0);
	fcntl(fd, F_SETFD, FD_CLOEXEC);
	dir->fd = fd;
	return (dir);
}
