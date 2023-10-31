/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_towards_angled.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:36:24 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/31 14:36:54 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

double	ft_move_towards_angled(double current, double target, double max_delta)
{
	const double	num = ft_delta_angled(current, target);

	if (0.0 - max_delta < num && num < max_delta)
		return (target);
	return (ft_move_towardsd(current, current + num, max_delta));
}
