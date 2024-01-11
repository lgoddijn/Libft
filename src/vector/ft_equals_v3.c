/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_equals_v3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:00:30 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:22:39 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_vector.h"

bool	ft_equals_v3(t_vector3 a, t_vector3 b)
{
	return ((a.x == b.x)
		&& (a.y == b.y)
		&& (a.z == b.z));
}