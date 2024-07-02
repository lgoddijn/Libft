/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_channel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:19:27 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/02 12:22:04 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_graphics.h"

void	ft_set_channel(t_pixel *pixel, t_channel channel, t_channel_type type)
{
	if (ft_isnull(pixel))
		return ;
	if (type == RED)
		*pixel = (*pixel & 0x00FFFFFF) | ((t_pixel)channel << (8 * 3));
	if (type == GREEN)
		*pixel = (*pixel & 0xFF00FFFF) | ((t_pixel)channel << (8 * 2));
	if (type == BLUE)
		*pixel = (*pixel & 0xFFFF00FF) | ((t_pixel)channel << (8 * 1));
	if (type == ALPHA)
		*pixel = (*pixel & 0xFFFFFF00) | ((t_pixel)channel);
}
