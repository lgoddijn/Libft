/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:22:14 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/14 19:10:50 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_print.h"

int32_t	ft_print_int(int32_t n)
{
	char	x;
	int32_t	c;

	c = 0;
	if (n == INT_MIN)
		return (ft_print_str("-2147483648"));
	else if (n < 0)
	{
		ft_print_char('-');
		n = -n;
		++c;
	}
	c += ft_digits((int64_t)n);
	if (n >= 10)
		ft_print_int(n / 10);
	x = (n % 10) + '0';
	ft_print_char(x);
	return (c);
}
