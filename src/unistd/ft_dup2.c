/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:09:48 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/02/01 19:05:19 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

int	ft_dup2(int __old, int __new)
{
	if (!__x86_64__)
		return (ARCH_FAIL);
	return ((int)__syscall(__NR_dup2, __old, __new));
}
