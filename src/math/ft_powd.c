/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_powd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 22:02:57 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/14 19:17:20 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_math.h"

double	ft_powd(double base, int32_t exp)
{
	double	result;

	if (exp == 0)
		return (1.0);
	if (exp < 0)
	{
		base = 1.0 / base;
		exp = -exp;
	}
	result = 1.0;
	while (exp)
	{
		if (exp & 1)
			result *= base;
		base *= base;
		exp >>= 1;
	}
	return (result);
}
