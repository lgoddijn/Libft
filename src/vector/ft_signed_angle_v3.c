/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signed_angle_v3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:35:03 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:23:40 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_vector.h"

float	ft_signed_angle_v3(t_vector3 from, t_vector3 to, t_vector3 axis)
{
	const float	num1 = ft_angle_v3(from, to);
	const float	num2 = from.y * to.z - from.z * to.y;
	const float	num3 = from.z * to.x - from.x * to.z;
	const float	num4 = from.x * to.y - from.y * to.x;

	return (num1 * ft_signf(
			(axis.x * num2)
			+ (axis.y * num3)
			+ (axis.z * num4)));
}
