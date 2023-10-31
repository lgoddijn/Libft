/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrtf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:15:04 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/26 18:31:30 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

float	ft_sqrtf(float n)
{
	const float		x2 = n * 0.5;
	const float		th = 1.5;
	union u_sqrtf	conv;

	conv.d = n;
	conv.i = 0x5fe6eb50c7b537a9 - (conv.i >> 1);
	conv.d *= (th - (x2 * conv.d * conv.d));
	return (1.0 / conv.d);
}
