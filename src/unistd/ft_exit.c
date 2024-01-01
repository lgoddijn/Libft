/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:24:20 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/01/01 19:20:51 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

void	ft_exit(int __status)
{
	if (!__x86_64__)
		return ;
	(void)__syscall(
		__NR_exit_group,
		__status);
}
