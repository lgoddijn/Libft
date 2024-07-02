/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:15:00 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/02 13:56:34 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_graphics.h"

t_pixel	ft_get_pixel(void *image, int32_t base_channel_buf_index)
{
	t_pixel	pixel;

	pixel = (t_pixel)0;
	if (base_channel_buf_index >= 0)
	{
		pixel = (t_pixel)image->pixels[base_channel_buf_index];
		pixel |= (t_pixel)image->pixels[base_channel_buf_index + 1] << 8;
		pixel |= (t_pixel)image->pixels[base_channel_buf_index + 2] << 16;
		pixel |= (t_pixel)image->pixels[base_channel_buf_index + 3] << 24;
	}
	return (pixel);
}
