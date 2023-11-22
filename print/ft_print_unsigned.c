/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:13:43 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/11/19 16:11:00 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_unsigned(const unsigned int n)
{
	char	x;
	int		c;

	c = 0;
	if (n >= 10)
		c += ft_print_unsigned(n / 10);
	x = (n % 10) + '0';
	c += ft_print_char(x);
	return (c);
}
