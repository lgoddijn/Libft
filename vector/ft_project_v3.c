/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_project_v3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:05:51 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/31 16:15:50 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_vector3	ft_project_v3(t_vector3 in_direction, t_vector3 on_normal)
{
	const float	num = ft_dot_v3(on_normal, on_normal);
	const float	num2 = ft_dot_v3(in_direction, on_normal);

	if (num < FLOAT_MIN_DENORMAL)
		return (in_direction);
	return (ft_init_v3(
			on_normal.x * num2 / num,
			on_normal.y * num2 / num,
			on_normal.z * num2 / num));
}
