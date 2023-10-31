/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_v3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:59:42 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/28 16:20:43 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_vector3	ft_max_v3(t_vector3 lhs, t_vector3 rhs)
{
	return (ft_init_v3(
			ft_maxf(lhs.x, rhs.x),
			ft_maxf(lhs.y, rhs.y),
			ft_maxf(lhs.z, rhs.z)));
}
