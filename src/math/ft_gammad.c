/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gammad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 22:20:24 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:26:15 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_math.h"

double	ft_gammad(double value, double absmax, double gamma)
{
	const bool		flag = value < 0.0;
	const double	num = ft_absf(value);
	const double	num2 = ft_powf(num / absmax, gamma) * absmax;

	if (num > absmax)
	{
		if (flag)
			return (0.0 - num);
		return (num);
	}
	if (flag)
		return (0.0 - num2);
	return (num2);
}
