/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_towards.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:06:33 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/31 14:40:27 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_move_towards(int current, int target, int max_delta)
{
	if (ft_abs(target - current) <= max_delta)
		return (target);
	return (current + ft_sign(target - current) * max_delta);
}
