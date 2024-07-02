/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphics.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 09:29:04 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/02 14:02:36 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GRAPHICS_H

# define FT_GRAPHICS_H

# include <stdint.h>
# include <stddef.h>
# include "ft_memory.h"
# include "ft_string.h"
# include "ft_vector.h"

// 100 MB / 4 bytes per pixel (RGBA)
# define MAX_BATCH_SIZE	26214400

/*
	Note:

		Pixels/Colors are represented as 32bit integers
		in the format RGBA. Meaning 8 bits per channel.
		A channel can therefore be represented as an
		8 bit integer which has enough memory to store
		a hexadecimal representation of the channel.
		Therefore the 32bit color can be handled as hex.
*/

typedef uint32_t	t_pixel;
typedef t_pixel		t_color32;
typedef t_byte		t_channel;

typedef enum e_channel_type
{
	RED,
	GREEN,
	BLUE,
	ALPHA
}	t_channel_type;

typedef enum e_direction
{
	LEFT,
	RIGHT,
	UP,
	DOWN
}	t_direction;

/*
	I would have used size_t instead of int32_t, but for
	the comfort of working with mlx its not worth it.
	
	Also a class would be really nice right now,
	I could just check the values at init and
	use my size_t stuff with simple properties.
*/

typedef struct s_window_size
{
	int32_t	width;
	int32_t	height;
}	t_window_size;

t_pixel		ft_build_pixel(t_byte channels[4]);
void		ft_set_channel(
				t_pixel *pixel,
				t_channel channel,
				t_channel_type type);
t_channel	ft_get_channel(t_pixel pixel, t_channel_type type);
t_pixel		ft_get_pixel(void *image, int32_t pixel_buf_index);
void		ft_set_pixel(void *image, int32_t pixel_buf_index, t_pixel pixel);
void		ft_populate_pixels(void *image, t_pixel *batch, size_t batch_size);
t_channel	ft_yield_channel(t_channel *buf, size_t size);
t_pixel		ft_yield_pixel(t_channel *buf, size_t size);
void		ft_iter_pixels(
				t_channel *buf,
				void (*apply)(t_pixel *),
				size_t size);

#endif