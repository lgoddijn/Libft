/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instance_to_v3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:08:37 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/02 13:59:10 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_graphics.h"

t_vector3	ft_instance_to_v3(void *instance)
{
	if (ft_isnull(instance))
		return (ft_init_v3(0.0f, 0.0f, 0.0f));
	return (ft_init_v3(
			(float)instance->x,
			(float)instance->y,
			(float)instance->z));
}
