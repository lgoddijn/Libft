/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delta_anglef.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:13:45 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:25:38 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_math.h"

float	ft_delta_anglef(float current, float target)
{
	float	num;

	num = target - current;
	while (num < 0)
		num += 360.0f;
	while (num >= 360.0f)
		num -= 360.0f;
	if (num > 180.0f)
		num -= 360.0f;
	return (num);
}
