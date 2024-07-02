/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_channel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:41:53 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/02 12:21:46 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_graphics.h"

t_channel	ft_get_channel(t_pixel pixel, t_channel_type type)
{
	if (type == RED)
		return ((pixel >> (8 * 3)) & 0XFF);
	if (type == GREEN)
		return ((pixel >> (8 * 2)) & 0xFF);
	if (type == BLUE)
		return ((pixel >> 8) & 0XFF);
	if (type == ALPHA)
		return (pixel & 0xFF);
}
