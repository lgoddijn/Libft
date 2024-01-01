/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdiv_v3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:05:03 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:23:35 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_vector.h"

t_vector3	ft_sdiv_v3(t_vector3 v, float k)
{
	if (k == 0.0f)
		return (v);
	return (ft_init_v3(v.x / k, v.y / k, v.z / k));
}
