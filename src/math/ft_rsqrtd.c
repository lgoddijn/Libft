/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rsqrtd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:53:33 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:28:48 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_math.h"

double	ft_rsqrtd(double n)
{
	const double	th = 1.5;
	union u_sqrtd	conv;

	conv.i = n;
	conv.i = 0x5fe6eb50c7b537a9 - (conv.i >> 1);
	conv.d *= (th - ((n * 0.5) * conv.d * conv.d));
	conv.d *= (th - ((n * 0.5) * conv.d * conv.d));
	return (conv.d);
}
