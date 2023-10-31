/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rsqrtf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:49:23 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/26 18:21:16 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

float	ft_rsqrtf(float n)
{
	const float		th = 1.5;
	union u_sqrtf	conv;

	conv.d = n;
	conv.i = 0x5fe6eb50c7b537a9 - (conv.i >> 1);
	conv.d *= (th - ((n * 0.5) * conv.d * conv.d));
	return (conv.d);
}
