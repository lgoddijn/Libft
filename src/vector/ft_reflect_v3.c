/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reflect_v3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:02:05 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:23:27 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_vector.h"

t_vector3	ft_reflect_v3(t_vector3 in_direction, t_vector3 in_normal)
{
	const float	num = -2.0f * ft_dot_v3(in_normal, in_direction);

	return (ft_init_v3(
			num * in_normal.x + in_direction.x,
			num * in_normal.y + in_direction.y,
			num * in_normal.z + in_direction.z));
}
