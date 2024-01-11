/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dot_v3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:08:40 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:22:32 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_vector.h"

float	ft_dot_v3(t_vector3 a, t_vector3 b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}