/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 00:28:12 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/10/16 17:42:42 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_dirent.h"

struct dirent	*ft_readdir(t_dir *dir)
{
	t_kernel_dirent	*lde;
	struct dirent	*de;
	int				len;

	if (dir->buf_pos >= dir->buf_end)
	{
		len = (int)__syscall3(__NR_getdents,
				dir->fd, (long)dir->buf, sizeof(dir->buf));
		if (len < 1)
		{
			if (len < 0 && len != -ENOENT)
				errno = -len;
			return (NULL);
		}
		dir->buf_end = len;
		dir->buf_pos = 0;
	}
	lde = (t_kernel_dirent *)(dir->buf + dir->buf_pos);
	de = __align_kernel_dirent(lde);
	dir->buf_pos += de->d_reclen;
	dir->tell = de->d_off;
	return (de);
}
