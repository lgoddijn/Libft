/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:58:59 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/14 18:19:09 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_math.h"

int32_t	ft_abs(int32_t x)
{
	t_bitmask32	mask;

	mask = x >> (sizeof(t_bitmask32) * 8 - 1);
	return ((x + mask) ^ mask);
}
