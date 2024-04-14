/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_towards.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:06:33 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/14 18:21:44 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_math.h"

int32_t	ft_move_towards(int32_t current, int32_t target, int32_t max_delta)
{
	if (ft_abs(target - current) <= max_delta)
		return (target);
	return (current + ft_sign(target - current) * max_delta);
}
