/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdatasync.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:43:45 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/01/01 16:45:37 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

int	ft_fdatasync(int __fd)
{
	if (!__x86_64__)
		return (ARCH_FAIL);
	return ((int)__syscall(
			__NR_fdatasync, __fd));
}
