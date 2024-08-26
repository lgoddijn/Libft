/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:26:36 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/08/26 18:48:42 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

_Noreturn void	ft_exit(int32_t __status)
{
	(void)__syscall1(__NR_exit, __status);
	while (1)
		(void)__syscall1(__NR_exit, __status);
}
