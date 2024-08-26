/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:29:01 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/08/26 18:50:29 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

int32_t	ft_open(const char *__path, int32_t __flag, ...)
{
	mode_t	mode;
	va_list	args;

	va_start(args, __flag);
	mode = va_arg(args, mode_t);
	va_end(args);
	return ((int32_t)__syscall3(__NR_open, (long)__path, __flag, mode));
}
