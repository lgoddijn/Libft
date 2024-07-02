/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_pixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:45:47 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/02 13:55:53 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_graphics.h"

t_pixel	ft_build_pixel(t_byte channels[4])
{
	t_pixel	pixel;

	pixel = (t_pixel)0;
	pixel |= (t_pixel)channels[0] << 24;
	pixel |= (t_pixel)channels[1] << 16;
	pixel |= (t_pixel)channels[2] << 8;
	pixel |= (t_pixel)channels[3];
	return (pixel);
}
