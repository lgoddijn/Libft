/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:58:59 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:24:54 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_math.h"

int	ft_abs(int x)
{
	t_bitmask32	mask;

	mask = x >> (sizeof(t_bitmask32) * 8 - 1);
	return ((x + mask) ^ mask);
}
