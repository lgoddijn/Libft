/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smooth_stepd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:45:48 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:29:18 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_math.h"

double	ft_smooth_stepd(double from, double to, double t)
{
	t = ft_clampd_0_1(t);
	t = -2.0 * t * t * t + 3.0 * t * t;
	return (to * t + from * (1.0 - t));
}
