/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clamp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:14:46 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/14 18:19:55 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_math.h"

int32_t	ft_clamp(int32_t value, int32_t min, int32_t max)
{
	if (value < min)
		value = min;
	else if (value > max)
		value = max;
	return (value);
}
