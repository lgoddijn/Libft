/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:30:12 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/14 19:07:58 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_math.h"

float	ft_logf(float x)
{
	const int32_t	max_iter = 10;
	float			result;
	float			term;
	int32_t			n;

	if (x <= 0)
		return (-1.0f / 0.0f);
	n = 0;
	result = 0.0f;
	term = x - 1.0f;
	while (++n <= max_iter)
	{
		result += term / n;
		term *= -x + 1.0f;
	}
	return (result);
}
