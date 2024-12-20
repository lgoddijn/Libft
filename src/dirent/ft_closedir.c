/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_closedir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 00:25:42 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/10/16 15:41:00 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_dirent.h"

int	ft_closedir(t_dir *dir)
{
	const int	ret = ft_close(dir->fd);

	free((void *)dir);
	return (ret);
}
