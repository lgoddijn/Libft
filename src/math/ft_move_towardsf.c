/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_towardsf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:05:20 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:28:22 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_math.h"

float	ft_move_towardsf(float current, float target, float max_delta)
{
	if (ft_absf(target - current) <= max_delta)
		return (target);
	return (current + ft_signf(target - current) * max_delta);
}
