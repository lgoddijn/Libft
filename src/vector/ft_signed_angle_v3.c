/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signed_angle_v3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:35:03 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/31 12:58:41 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_vector.h"

static __inline__ float	signf(float x)
{
	if (x > 0.0f)
		return (1.0f);
	else if (x < 0.0f)
		return (-1.0f);
	else
		return (0.0f);
}

float	ft_signed_angle_v3(t_vector3 from, t_vector3 to, t_vector3 axis)
{
	const float	num1 = ft_angle_v3(from, to);
	const float	num2 = from.y * to.z - from.z * to.y;
	const float	num3 = from.z * to.x - from.x * to.z;
	const float	num4 = from.x * to.y - from.y * to.x;

	return (num1 * signf(
			(axis.x * num2)
			+ (axis.y * num3)
			+ (axis.z * num4)));
}
