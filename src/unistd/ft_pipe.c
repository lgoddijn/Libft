/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 18:21:59 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/01/01 20:45:40 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

int	ft_pipe(int __fd[2])
{
	if (!__x86_64__)
		return (ARCH_FAIL);
	return ((int)__syscall(__NR_pipe, (long)__fd));
}
