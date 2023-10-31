/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_towards_anglef.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:07:39 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/29 15:16:08 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

float	ft_move_towards_anglef(float current, float target, float max_delta)
{
	const float	num = ft_delta_anglef(current, target);

	if (0.0f - max_delta < num && num < max_delta)
		return (target);
	return (ft_move_towardsf(current, current + num, max_delta));
}
