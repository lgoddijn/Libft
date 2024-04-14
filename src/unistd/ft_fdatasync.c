/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdatasync.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:43:45 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/14 18:38:21 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

int32_t	ft_fdatasync(int32_t __fd)
{
	if (!__x86_64__)
		return (ARCH_FAIL);
	return ((int32_t)__syscall(
			__NR_fdatasync, __fd));
}
