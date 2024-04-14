/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:33:18 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/14 19:07:44 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_math.h"

double	ft_logd(double x)
{
	const int32_t	max_iter = 10;
	double			result;
	double			term;
	int32_t			n;

	if (x <= 0)
		return (-1.0 / 0.0);
	n = 0;
	result = 0.0;
	term = x - 1.0;
	while (++n <= max_iter)
	{
		result += term / n;
		term *= -x + 1.0;
	}
	return (result);
}
