/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raise.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:44:47 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/19 23:47:28 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_print.h"

static void	flag_parse(const char flag, va_list args)
{
	if (flag == 'c')
		ft_print_char(va_arg(args, int32_t));
	if (flag == 's')
		ft_print_str(va_arg(args, char *));
	if (flag == 'p')
		ft_print_ptr(va_arg(args, void *));
	if (flag == 'd' || flag == 'i')
		ft_print_int(va_arg(args, int32_t));
	if (flag == 'u')
		ft_print_uint((int32_t)va_arg(args, uint32_t));
	if (flag == 'X')
		ft_print_hex(va_arg(args, uint32_t), true, false);
	if (flag == 'x')
		ft_print_hex(va_arg(args, uint32_t), false, false);
	if (flag == '%')
		ft_print_char('%');
}

static void	print_msg(const char *msg, va_list args)
{
	while (*msg)
	{
		if (*msg == '%' && *(msg + 1))
			flag_parse(*++msg, args);
		else
			ft_write(1, msg, 1);
		++msg;
	}
}

void	ft_throw(const char *msg, ...)
{
	va_list	args;

	if (!msg)
		return ;
	va_start(args, msg);
	ft_write(1, "\033[1;91m[FATAL]\033[0m ", 20);
	print_msg(msg, args);
	ft_write(1, "\n", 1);
	va_end(args);
	exit(EXIT_FAILURE);
}
