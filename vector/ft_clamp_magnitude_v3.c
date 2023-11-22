/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clamp_magnitude_v3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:41:55 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/11/08 14:58:23 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_vector3	ft_clamp_magnitude_v3(t_vector3 v, float max_len)
{
	const float	num1 = ft_sqr_magnitude_v3(v);
	const float	num2 = sqrtf(num1);
	const float	num3 = v.x / num2;
	const float	num4 = v.y / num2;
	const float	num5 = v.z / num2;

	if (num1 < max_len * max_len)
		return (v);
	return (ft_init_v3(
			num3 * max_len,
			num4 * max_len,
			num5 * max_len));
}
