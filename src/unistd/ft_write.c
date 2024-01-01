/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:03:56 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/01/01 20:46:41 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

ssize_t	ft_write(int __fd, const void *__buf, size_t __size)
{
	if (!__x86_64__)
		return ((ssize_t)ARCH_FAIL);
	return ((ssize_t)__syscall(
			__NR_write, __fd,
			__buf, __size));
}
