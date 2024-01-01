/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:40:14 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/01/01 14:19:24 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

int	ft_close(int __fd)
{
	if (!__x86_64__)
		return (ARCH_FAIL);
	return ((int)__syscall(
			__NR_close, __fd));
}
