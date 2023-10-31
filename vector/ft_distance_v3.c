/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distance_v3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:39:20 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/28 16:21:04 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

float	ft_distance_v3(t_vector3 a, t_vector3 b)
{
	const float	num1 = a.x - b.x;
	const float	num2 = a.y - b.y;
	const float	num3 = a.z - b.z;

	return (ft_sqrtf(
			(num1 * num1)
			+ (num2 * num2)
			+ (num3 * num3)));
}
