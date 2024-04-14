/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lseek.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 18:07:56 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/14 18:40:22 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

off_t	ft_lseek(int32_t __fd, off_t __offset, int32_t __whence)
{
	if (!__x86_64__)
		return ((off_t)ARCH_FAIL);
	return (__syscall(__NR_lseek, __fd, __offset, __whence));
}
