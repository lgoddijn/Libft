/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clamp_0_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:17:15 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/14 18:19:44 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_math.h"

int32_t	ft_clamp_0_1(int32_t value)
{
	if (value < 0)
		return (0);
	if (value > 1)
		return (1);
	return (value);
}
