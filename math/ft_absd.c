/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fast_abs_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:25:48 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/29 22:07:01 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

double	ft_absd(double x)
{
	union u_absd	absd;

	absd.f = x;
	absd.i &= 0x7FFFFFFFFFFFFFFF;
	return (absd.f);
}
