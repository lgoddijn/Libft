/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_angle_v3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:30:40 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:22:01 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_vector.h"

float	ft_angle_v3(t_vector3 from, t_vector3 to)
{
	const float	num1 = ft_sqr_magnitude_v3(from);
	const float	num2 = ft_sqr_magnitude_v3(to);
	const float	num3 = num1 * num2;

	if (num3 < KEPSILON_NORMAL_SQRT)
		return (0.0f);
	return (acosf(num2) * RAD2DEG);
}
