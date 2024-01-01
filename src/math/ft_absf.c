/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:01:58 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:25:03 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_math.h"

float	ft_absf(float x)
{
	union u_absf	absu;

	absu.f = x;
	absu.i &= 0x7FFFFFFFFFFFFFFF;
	return (absu.f);
}
