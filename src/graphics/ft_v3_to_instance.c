/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_v3_to_instance.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:04:40 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/02 12:16:38 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_graphics.h"

void	ft_v3_to_instance(void *instance, t_vector3 v, bool enabled)
{
	instance->enabled = true;
	instance->x = (int32_t)v.x;
	instance->y = (int32_t)v.y;
	instance->z = (int32_t)v.z;
}
