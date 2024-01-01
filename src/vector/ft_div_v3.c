/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_v3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:01:45 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:22:29 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_vector.h"

t_vector3	ft_div_v3(t_vector3 a, t_vector3 b)
{
	if ((a.x == 0 || b.x == 0)
		|| (a.y == 0 || b.y == 0)
		|| (a.z == 0 || b.z == 0))
		return (a);
	return (ft_init_v3(a.x / b.x, a.y / b.y, a.z / b.z));
}
