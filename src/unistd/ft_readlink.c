/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readlink.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:01:31 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/19 12:09:38 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

ssize_t ft_readlink(const char *restrict path, char *restrict buf, size_t size)
{
	char	dummy[1];
	int32_t	ret;

	if (!size)
	{
		buf = dummy;
		size = 1;
	}
	if (__READLINK_NR == __NR_readlinkat)
		ret = __syscall(__READLINK_NR, AT_FDCWD, path, size);
	else
		ret = __syscall(__READLINK_NR, path, buf, size);
	if (buf == dummy && ret > 0)
		ret = 0;
	return ((ssize_t)ret);
}
