/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slerp_v3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:00:28 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/11/08 15:22:42 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_vector3	ft_slerp_v3(t_vector3 v1, t_vector3 v2, float t)
{
	const float	theta = acosf(ft_clampf(ft_dot_v3(v1, v2), -1.0f, 1.0f));
	const float	st = sinf(theta);
	const float	coeff1 = sinf((1.0f - t) * theta) / st;
	const float	coeff2 = sinf(t * theta) / st;

	if (ft_absf(st) < KEPSILON)
		return (ft_lerp_v3(v1, v2, t));
	return (ft_init_v3(
			coeff1 * v1.x + coeff2 * v2.x,
			coeff1 * v1.y + coeff2 * v2.y,
			coeff1 * v1.z + coeff2 * v2.z));
}
