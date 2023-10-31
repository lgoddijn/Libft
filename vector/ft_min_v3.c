/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_v3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:51:31 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/28 16:20:41 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_vector3	ft_min_v3(t_vector3 lhs, t_vector3 rhs)
{
	return (ft_init_v3(
			ft_minf(lhs.x, rhs.x),
			ft_minf(lhs.y, rhs.y),
			ft_minf(lhs.z, rhs.z)));
}
