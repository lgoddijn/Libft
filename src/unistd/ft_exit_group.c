/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_group.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:24:20 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/08/26 18:48:37 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

_Noreturn void	ft_exit_group(int32_t __status)
{
	(void)__syscall1(__NR_exit_group, __status);
	while (1)
		(void)__syscall1(__NR_exit_group, __status);
}
