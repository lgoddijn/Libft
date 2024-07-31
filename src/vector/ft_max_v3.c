/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_v3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:59:42 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/31 12:57:21 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_vector.h"

static __inline__ float	maxf(float x, float y)
{
	if (x > y)
		return (x);
	return (y);
}

t_vector3	ft_max_v3(t_vector3 lhs, t_vector3 rhs)
{
	return (ft_init_v3(
			maxf(lhs.x, rhs.x),
			maxf(lhs.y, rhs.y),
			maxf(lhs.z, rhs.z)));
}
