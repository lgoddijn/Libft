/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readdir_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 00:37:41 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/10/16 15:38:48 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_dirent.h"

int	ft_readdir_r(
	t_dir *__restrict__ dir,
	struct dirent *__restrict__ buf,
	struct dirent **__restrict__ result)
{
	const int		errnotmp = errno;
	int				ret;
	struct dirent	*de;

	errno = 0;
	de = ft_readdir(dir);
	ret = errno;
	if (ret)
		return (ret);
	errno = errnotmp;
	if (de)
		ft_memcpy(buf, de, de->d_reclen);
	else
		buf = NULL;
	*result = buf;
	return (0);
}
