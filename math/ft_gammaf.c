/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gammaf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:53:29 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/29 22:20:18 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

float	ft_gammaf(float value, float absmax, float gamma)
{
	const bool	flag = value < 0.0f;
	const float	num = ft_absf(value);
	const float	num2 = ft_powf(num / absmax, gamma) * absmax;

	if (num > absmax)
	{
		if (flag)
			return (0.0f - num);
		return (num);
	}
	if (flag)
		return (0.0f - num2);
	return (num2);
}
