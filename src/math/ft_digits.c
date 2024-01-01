/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:11:37 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:25:42 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_math.h"

size_t	ft_digits(long n)
{
	size_t	digits;

	digits = 0;
	if (n <= 0)
		++digits;
	while (n != 0)
	{
		++digits;
		n /= 10;
	}
	return (digits);
}
