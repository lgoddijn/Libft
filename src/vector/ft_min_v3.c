/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_v3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:51:31 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/31 12:57:25 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_vector.h"

static __inline__ float	minf(float x, float y)
{
	if (x < y)
		return (x);
	return (y);
}

t_vector3	ft_min_v3(t_vector3 lhs, t_vector3 rhs)
{
	return (ft_init_v3(
			minf(lhs.x, rhs.x),
			minf(lhs.y, rhs.y),
			minf(lhs.z, rhs.z)));
}
