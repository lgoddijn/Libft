/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:37:19 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/02/02 17:39:07 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

int	ft_execve(const char *__path, char *const __argv[], char *const __envp[])
{
	if (!__x86_64__)
		return (ARCH_FAIL);
	return ((int)__syscall(__NR_execve, __path, __argv, __envp));
}
