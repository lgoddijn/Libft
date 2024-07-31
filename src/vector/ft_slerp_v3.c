/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slerp_v3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:00:28 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/31 13:02:10 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_vector.h"

static __inline__ float	clampf(float value, float lower, float upper)
{
	if (value < lower)
		return (lower);
	else if (value > upper)
		return (upper);
	else
		return (value);
}

static __inline__ float	absf(float x)
{
	if (x < 0.0f)
		return (-x);
	return (x);
}

t_vector3	ft_slerp_v3(t_vector3 v1, t_vector3 v2, float t)
{
	const float	theta = acosf(clampf(ft_dot_v3(v1, v2), -1.0f, 1.0f));
	const float	st = sinf(theta);
	const float	coeff1 = sinf((1.0f - t) * theta) / st;
	const float	coeff2 = sinf(t * theta) / st;

	if (absf(st) < KEPSILON)
		return (ft_lerp_v3(v1, v2, t));
	return (ft_init_v3(
			coeff1 * v1.x + coeff2 * v2.x,
			coeff1 * v1.y + coeff2 * v2.y,
			coeff1 * v1.z + coeff2 * v2.z));
}
