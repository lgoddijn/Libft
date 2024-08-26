/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:37:19 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/08/26 19:04:15 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

int32_t	ft_execve(
	const char *__path,
	char *const __argv[],
	char *const __envp[]
	)
{
	return ((int32_t)__syscall3(
			__NR_execve,
			(long)__path,
			(long)__argv,
			(long)__envp));
}
