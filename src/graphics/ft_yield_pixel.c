/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_yield_pixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:33:19 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/02 13:17:19 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_graphics.h"

t_pixel	ft_yield_pixel(t_channel *buf, size_t size)
{
	static int		index = 0;
	t_pixel			pixel;

	pixel = (t_pixel)0;
	if (ft_isnull(buf))
		return (pixel);
	if (index + 4 > size)
		index = 0;
	pixel = (t_pixel)buf[index++];
	pixel |= (t_pixel)buf[index++] << 8;
	pixel |= (t_pixel)buf[index++] << 16;
	pixel |= (t_pixel)buf[index++] << 24;
	return (pixel);
}
