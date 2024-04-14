/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_symlink.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 18:47:27 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/14 18:42:04 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

int32_t	ft_symlink(const char *__existing, const char *__new)
{
	if (!__x86_64__)
		return (ARCH_FAIL);
	return ((int32_t)__syscall(
			__NR_symlink,
			(int64_t)__existing,
			(int64_t)__new));
}
