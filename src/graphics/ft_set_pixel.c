/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:14:23 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/02 13:29:57 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_graphics.h"

void	ft_set_pixel(void *image, int32_t base_channel_buf_index, t_pixel pixel)
{
	if (base_channel_buf_index >= 0)
	{
		image->pixels[base_channel_buf_index] = (t_channel)pixel;
		image->pixels[base_channel_buf_index + 1] = (t_channel)pixel >> 8;
		image->pixels[base_channel_buf_index + 2] = (t_channel)pixel >> 16;
		image->pixels[base_channel_buf_index + 3] = (t_channel)pixel >> 24;
	}
}
