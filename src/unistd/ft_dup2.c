/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:09:48 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/14 18:36:51 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

int32_t	ft_dup2(int32_t __old, int32_t __new)
{
	if (!__x86_64__)
		return (ARCH_FAIL);
	return ((int32_t)__syscall(__NR_dup2, __old, __new));
}
