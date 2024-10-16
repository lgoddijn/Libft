/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opendir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 00:24:19 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/10/16 15:45:30 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_dirent.h"

t_dir	*ft_opendir(const char *path)
{
	t_dir	*dir;
	int		fd;

	fd = ft_open(path, O_RDONLY | __O_DIRECTORY | __O_CLOEXEC);
	if (fd < 0)
		return (0);
	dir = (t_dir *)ft_calloc(1, sizeof(*dir));
	if (!dir)
	{
		ft_close(fd);
		return (0);
	}
	dir->fd = fd;
	return (dir);
}
