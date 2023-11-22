/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:22:14 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/11/20 16:25:31 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_int(int n)
{
	char	x;
	int		c;

	c = 0;
	if (n == INT_MIN)
		return (ft_print_str("-2147483648"));
	else if (n < 0)
	{
		ft_print_char('-');
		n = -n;
		++c;
	}
	c += ft_digits((long)n);
	if (n >= 10)
		ft_print_int(n / 10);
	x = (n % 10) + '0';
	ft_print_char(x);
	return (c);
}
