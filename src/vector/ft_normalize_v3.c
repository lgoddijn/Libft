/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize_v3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:32:51 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:23:18 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_vector.h"

t_vector3	ft_normalize_v3(t_vector3 v)
{
	const float	magnitude = ft_magnitude_v3(v);

	if (magnitude > KEPSILON)
		return (ft_sdiv_v3(v, magnitude));
	return (ft_init_v3(0.0f, 0.0f, 0.0f));
}
