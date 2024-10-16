/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rewinddir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 00:43:52 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/10/16 15:39:24 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_dirent.h"

void	ft_rewinddir(t_dir *dir)
{
	ft_lseek(dir->fd, 0, SEEK_SET);
	dir->buf_end = 0;
	dir->buf_pos = dir->buf_end;
	dir->tell = 0;
}
