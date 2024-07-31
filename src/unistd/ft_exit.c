/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:24:20 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/31 13:25:25 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

_Noreturn void	ft_exit(int32_t __status)
{
	(void)__syscall(__NR_exit_group, __status);
	while (1)
		(void)__syscall(__NR_exit_group, __status);
}
