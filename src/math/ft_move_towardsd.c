/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_towardsd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:39:41 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:28:16 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_math.h"

double	ft_move_towardsd(double current, double target, double max_delta)
{
	if (ft_absd(target - current) <= max_delta)
		return (target);
	return (current + ft_signd(target - current) * max_delta);
}
