# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/02 09:28:33 by lgoddijn          #+#    #+#              #
#    Updated: 2024/07/02 14:13:24 by lgoddijn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= graphics.a

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -Wstrict-prototypes		\
		  -Wmissing-prototypes -Wpedantic -std=c99		\
		  -fstack-protector-strong -O2 -g -I../../include

SRC		= ft_build_pixel.c		\
		  ft_get_channel.c		\
		  ft_get_pixel.c		\
		  ft_init_window_size.c	\
		  ft_instance_to_v3.c	\
		  ft_iter_pixels.c		\
		  ft_populate_pixels.c	\
		  ft_set_channel.c		\
		  ft_set_pixel.c		\
		  ft_str_to_color.c		\
		  ft_v3_to_instance.c	\
		  ft_yield_channel.c	\
		  ft_yield_pixel.c

OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $(OBJ)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(NAME)

re: clean all

.PHONY: all clean re