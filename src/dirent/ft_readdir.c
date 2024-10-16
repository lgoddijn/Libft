/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 00:28:12 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/10/16 00:30:26 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_dirent.h"

struct dirent	*ft_readdir(DIR *dir)
{
	struct dirent	*de;
	int				len;

	if (dir->buf_pos >= dir->buf_end)
	{
		len = __syscall3(__NR_getdents, dir->fd, dir->buf, sizeof(dir->buf));
		if (len <= 0)
		{
			if (len < 0 && len != -ENOENT)
				errno = -len;
			return (0);
		}
		dir->buf_end = len;
		dir->buf_pos = 0;
	}
	de = (void *)(dir->buf + dir->buf_pos);
	dir->buf_pos += de->d_reclen;
	dir->tell = de->d_off;
	return (de);
}
