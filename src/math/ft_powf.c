/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_powf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:07:08 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/14 19:17:23 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_math.h"

float	ft_powf(float base, int32_t exp)
{
	float	result;

	if (exp == 0)
		return (1.0f);
	if (exp < 0)
	{
		base = 1.0f / base;
		exp = -exp;
	}
	result = 1.0f;
	while (exp)
	{
		if (exp & 1)
			result *= base;
		base *= base;
		exp >>= 1;
	}
	return (result);
}
