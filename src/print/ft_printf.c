/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:07:39 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/14 18:26:00 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_print.h"

static int32_t	ft_flag_parse(const char flag, va_list args)
{
	if (flag == 'c')
		return (ft_print_char(va_arg(args, int32_t)));
	if (flag == 's')
		return (ft_print_str(va_arg(args, char *)));
	if (flag == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	if (flag == 'd' || flag == 'i')
		return (ft_print_int(va_arg(args, int32_t)));
	if (flag == 'u')
		return (ft_print_uint((int32_t)va_arg(args, uint32_t)));
	if (flag == 'X')
		return (ft_print_hex(va_arg(args, uint32_t), true, false));
	if (flag == 'x')
		return (ft_print_hex(va_arg(args, uint32_t), false, false));
	if (flag == '%')
		return (ft_print_char('%'));
	return (1);
}

static int32_t	ft_buf_fmt(const char *fmt, va_list args)
{
	int32_t	c;

	c = 0;
	while (*fmt)
	{
		if (*fmt == '%' && *(fmt + 1))
			c += ft_flag_parse(*++fmt, args);
		else
		{
			ft_write(1, fmt, 1);
			++c;
		}
		++fmt;
	}
	return (c);
}

int32_t	ft_printf(const char *fmt, ...)
{
	int32_t	c;
	va_list	args;

	if (!fmt)
		return (-1);
	va_start(args, fmt);
	c = ft_buf_fmt(fmt, args);
	va_end(args);
	return (c);
}
