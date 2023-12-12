/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raise.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:44:47 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/05 15:28:04 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	flag_parse(const char flag, va_list args)
{
	if (flag == 'c')
		ft_print_char(va_arg(args, int));
	if (flag == 's')
		ft_print_str(va_arg(args, char *));
	if (flag == 'p')
		ft_print_ptr(va_arg(args, void *));
	if (flag == 'd' || flag == 'i')
		ft_print_int(va_arg(args, int));
	if (flag == 'u')
		ft_print_unsigned((int)va_arg(args, unsigned int));
	if (flag == 'X')
		ft_print_hex(va_arg(args, unsigned int), true, false);
	if (flag == 'x')
		ft_print_hex(va_arg(args, unsigned int), false, false);
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
			write(1, msg, 1);
		++msg;
	}
}

void	ft_raise(const char *msg, ...)
{
	va_list	args;

	if (!msg)
		return ;
	va_start(args, msg);
	write(1, "\e[1;91m[FATAL]\e[0m ", 20);
	print_msg(msg, args);
	write(1, "\n", 1);
	va_end(args);
	exit(EXIT_FAILURE);
}
