/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqr_magnitude_v3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:12:47 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:23:53 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_vector.h"

float	ft_sqr_magnitude_v3(t_vector3 v)
{
	return ((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}
