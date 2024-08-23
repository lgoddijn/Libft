/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readlink.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:01:31 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/08/21 19:14:26 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

ssize_t	ft_readlink(const char *restrict path, char *restrict buf, size_t size)
{
	#ifdef __NR_readlink
		return ((ssize_t)__syscall(__NR_readlink, path, buf, size));
	#else
		return ((ssize_t)__syscall(__NR_readlinkat, AT_FDCWD, path, buf, size));
	#endif
}
