/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fsync.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:46:10 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/14 18:38:25 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

int32_t	ft_fsync(int32_t __fd)
{
	if (!__x86_64__)
		return (ARCH_FAIL);
	return ((int32_t)__syscall(
			__NR_fsync, __fd));
}
