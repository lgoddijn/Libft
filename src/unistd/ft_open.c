/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:29:01 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/01/01 14:13:12 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

int	ft_open(const char *__path, int __flag, ...)
{
	mode_t	mode;
	va_list	args;

	if (!__x86_64__)
		return (ARCH_FAIL);
	va_start(args, __flag);
	mode = va_arg(args, mode_t);
	va_end(args);
	return ((int)__syscall(
			__NR_open, __path,
			__flag, mode));
}
