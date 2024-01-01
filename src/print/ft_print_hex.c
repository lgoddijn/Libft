/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:30:21 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:01:48 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_print.h"

static char	*ft_handle_cases(long long *n, int *c,
			const bool is_upper, const bool is_ptr)
{
	char	*digits;

	digits = "0123456789abcdef";
	if (is_upper)
		digits = "0123456789ABCDEF";
	if (is_ptr)
		*c += ft_print_str("0x");
	if (*n == 0)
	{
		ft_print_char('0');
		return (NULL);
	}
	if (*n < 0)
	{
		*n = -*n;
		ft_print_char('-');
		++*c;
	}
	return (digits);
}

int	ft_print_hex(long long n, const bool is_upper, const bool is_ptr)
{
	char				*digits;
	unsigned long long	t;
	int					i;
	int					c;

	c = 0;
	i = 0;
	digits = ft_handle_cases(&n, &c, is_upper, is_ptr);
	if (!digits)
		return (++c);
	t = n;
	while (t != 0)
	{
		++i;
		t >>= 4;
	}
	while (--i >= 0 && ++c)
		ft_print_char(digits[(n >> (i * 4)) & 0xF]);
	return (c);
}
