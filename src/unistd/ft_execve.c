/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:37:19 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/31 13:25:06 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

int32_t	ft_execve(
	const char *__path,
	char *const __argv[],
	char *const __envp[]
	)
{
	return ((int32_t)__syscall(__NR_execve, __path, __argv, __envp));
}
