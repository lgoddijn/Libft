/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readlink.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:01:31 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/08/26 18:50:48 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

#if defined(__NR_readlink)

ssize_t	ft_readlink(
		const char *path,
		char *buf, size_t size
		)
{
	return ((ssize_t)__syscall3(__NR_readlink, (long)path, (long)buf, size));
}

#else

ssize_t	ft_readlink(
		const char *path,
		char *buf, size_t size
		)
{
	return ((ssize_t)__syscall4(__NR_readlinkat,
			(long [4]){AT_FDCWD, (long)path, (long)buf, size}));
}

#endif
