/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:13:15 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/14 18:21:49 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_math.h"

int32_t	ft_pow(int32_t base, int32_t exp)
{
	int32_t	result;

	if (exp == 0)
		return (1);
	if (exp < 0)
		return (0);
	result = 1;
	while (exp)
	{
		if (exp & 1)
			result *= base;
		base *= base;
		exp >>= 1;
	}
	return (result);
}
