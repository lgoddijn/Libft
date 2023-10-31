/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrtd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:51:32 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/26 21:53:43 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

double	ft_sqrtd(double n)
{
	const double	x2 = n * 0.5;
	const double	th = 1.5;
	union u_sqrtd	conv;

	conv.d = n;
	conv.i = 0x5fe6eb50c7b537a9 - (conv.i >> 1);
	conv.d *= (th - (x2 * conv.d * conv.d));
	conv.d *= (th - (x2 * conv.d * conv.d));
	return (1.0 / conv.d);
}
