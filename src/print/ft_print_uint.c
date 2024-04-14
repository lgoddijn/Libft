/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:13:43 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/14 18:24:49 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_print.h"

int32_t	ft_print_uint(const uint32_t n)
{
	char	x;
	int32_t	c;

	c = 0;
	if (n >= 10)
		c += ft_print_uint(n / 10);
	x = (n % 10) + '0';
	c += ft_print_char(x);
	return (c);
}
