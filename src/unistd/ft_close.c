/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:40:14 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/14 18:36:37 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

int32_t	ft_close(int32_t __fd)
{
	if (!__x86_64__)
		return (ARCH_FAIL);
	return ((int32_t)__syscall(
			__NR_close, __fd));
}
