/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iter_pixels.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:18:37 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/02 13:59:42 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_graphics.h"

void	ft_iter_pixels(t_channel *buf, void (*apply)(t_pixel *), size_t size)
{
	size_t	i;

	i = 0;
	if (ft_isnull(apply))
		return ;
	while (i < size)
		apply(buf[i++]);
}
