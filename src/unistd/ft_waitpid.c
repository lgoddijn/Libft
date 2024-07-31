/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_waitpid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:25:23 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/31 13:29:57 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

pid_t	ft_waitpid(pid_t __pid, int32_t *__status, int32_t __options)
{
	return ((pid_t)__syscall(__NR_wait4, __pid, __status, __options, 0));
}
