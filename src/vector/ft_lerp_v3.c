/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lerp_v3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:40:08 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/31 13:44:49 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_vector.h"

static __inline__ float	clampf_0_1(float x)
{
	if (x < 0.0f)
		return (0.0f);
	else if (x > 1.0f)
		return (1.0f);
	else
		return (x);
}

t_vector3	ft_lerp_v3(t_vector3 a, t_vector3 b, float t)
{
	return (ft_lerp_unclamped_v3(a, b, clampf_0_1(t)));
}
