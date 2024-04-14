/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chmod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 20:10:23 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/14 18:34:28 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

int32_t	ft_chmod(const char *__path, mode_t __mode)
{
	if (!__x86_64__)
		return (ARCH_FAIL);
	return ((int32_t)__syscall(__NR_chmod, __path, __mode));
}
