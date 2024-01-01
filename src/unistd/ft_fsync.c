/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fsync.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:46:10 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/01/01 16:47:09 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

int	ft_fsync(int __fd)
{
	if (!__x86_64__)
		return (ARCH_FAIL);
	return ((int)__syscall(
			__NR_fsync, __fd));
}
