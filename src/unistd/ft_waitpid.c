/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_waitpid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:25:23 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/02/02 16:29:05 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

pid_t	ft_waitpid(pid_t __pid, int *__status, int __options)
{
	if (!__x86_64__)
		return ((pid_t)ARCH_FAIL);
	return ((pid_t)__syscall(__NR_wait4, __pid, __status, __options, 0));
}
