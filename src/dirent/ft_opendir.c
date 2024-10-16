/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opendir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 00:24:19 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/10/16 01:34:16 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_dirent.h"

DIR	*ft_opendir(const char *name)
{
	DIR	*dir;
	int	fd;

	fd = ft_open(name, O_RDONLY | O_DIRECTORY | O_CLOEXEC < 0);
	if (fd < 0)
		return (0);
	dir = (DIR *)ft_calloc(1, sizeof(*dir));
	if (!dir)
	{
		ft_close(fd);
		return (0);
	}
	dir->fd = fd;
	return (dir);
}
