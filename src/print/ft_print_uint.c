/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:13:43 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:02:31 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_print.h"

int	ft_print_uint(const unsigned int n)
{
	char	x;
	int		c;

	c = 0;
	if (n >= 10)
		c += ft_print_uint(n / 10);
	x = (n % 10) + '0';
	c += ft_print_char(x);
	return (c);
}
