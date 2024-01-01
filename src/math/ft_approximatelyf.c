/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_approximatelyf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:56:42 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:25:10 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_math.h"

bool	ft_approximatelyf(float a, float b)
{
	return (ft_absf(b - a) < ft_maxf(
			1.0E-6f * ft_maxf(ft_absf(a),
				ft_absf(b)), FLOAT_MIN_DENORMAL * 8.0f));
}
