/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:01:58 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/29 22:07:29 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

float	ft_absf(float x)
{
	union u_absf	absu;

	absu.f = x;
	absu.i &= 0x7FFFFFFFFFFFFFFF;
	return (absu.f);
}
