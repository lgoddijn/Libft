/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:25:48 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:24:58 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_math.h"

double	ft_absd(double x)
{
	union u_absd	absd;

	absd.f = x;
	absd.i &= 0x7FFFFFFFFFFFFFFF;
	return (absd.f);
}
