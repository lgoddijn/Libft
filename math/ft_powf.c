/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fast_powf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:07:08 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/29 22:06:16 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

float	ft_powf(float base, int exp)
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
