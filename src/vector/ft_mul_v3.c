/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mul_v3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:11:12 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:23:15 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_vector.h"

t_vector3	ft_mul_v3(t_vector3 a, t_vector3 b)
{
	return (ft_init_v3(a.x * b.x, a.y * b.y, a.z * b.z));
}