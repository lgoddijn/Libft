/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_populate_pixels.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:17:57 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/02 12:15:26 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_graphics.h"

void	ft_populate_pixels(void *image, t_pixel *batch, size_t batch_size)
{
	int	i;

	i = 0;
	if (ft_isanynull(2, image, pixels))
		return ;
	if (batch_size > MAX_BATCH_SIZE)
		return ;
	while (batch_size--)
	{
		ft_set_pixel(image, i, batch[i]);
		i += 4;
	}
}
