# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/31 18:29:47 by lgoddijn          #+#    #+#              #
#    Updated: 2024/07/16 19:05:59 by lgoddijn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= vector.a

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -Wstrict-prototypes		\
		  -Wmissing-prototypes -Wpedantic -std=gnu17	\
		  -fstack-protector-strong -O2 -g -I../../include

SRC		= ft_add_v3.c				\
		  ft_aggregate_v3.c			\
		  ft_angle_v3.c				\
		  ft_clamp_magnitude_v3.c	\
		  ft_conjugate_v3.c			\
		  ft_cross_v3.c				\
		  ft_distance_v3.c			\
		  ft_div_v3.c				\
		  ft_dot_v3.c				\
		  ft_equals_v3.c			\
		  ft_init_v3.c				\
		  ft_lerp_unclamped_v3.c	\
		  ft_lerp_v3.c				\
		  ft_magnitude_v3.c			\
		  ft_max_v3.c				\
		  ft_min_v3.c				\
		  ft_move_towards_v3.c		\
		  ft_mul_v3.c				\
		  ft_normalize_v3.c			\
		  ft_project_v3.c			\
		  ft_reflect_v3.c			\
		  ft_scale_v3.c				\
		  ft_sdiv_v3.c				\
		  ft_signed_angle_v3.c		\
		  ft_slerp_v3.c				\
		  ft_sqr_magnitude_v3.c		\
		  ft_sub_v3.c				\
		  ft_sum_v3.c				\
		  ft_remains_v3.c			\
		  ft_product_v3.c			\
		  ft_mean_v3.c

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