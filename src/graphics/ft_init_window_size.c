/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_window_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:56:19 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/02 12:08:17 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_graphics.h"

t_window_size	*ft_init_window_size(int32_t width, int32_t height)
{
	t_window_size	*window_size;

	window_size = (t_window_size *)malloc(
			sizeof(t_window_size));
	if (ft_isnull(window_size))
		return (NULL);
	window_size->width = width;
	window_size->height = height;
	return (window_size);
}
