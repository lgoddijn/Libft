/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_approximatelyd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 22:13:39 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:25:07 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_math.h"

bool	ft_approximatelyd(double a, double b)
{
	return (ft_absd(b - a) < ft_maxd(
			1.0E-6 * ft_maxd(ft_absd(a),
				ft_absd(b)), FLOAT_MIN_DENORMAL * 8.0));
}
