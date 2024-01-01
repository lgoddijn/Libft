# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/31 18:29:47 by lgoddijn          #+#    #+#              #
#    Updated: 2023/12/31 18:43:54 by lgoddijn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= math.a

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -Wstrict-prototypes \
		  -Wmissing-prototypes -Wpedantic -std=c99  \
		  -fstack-protector-strong -O2 -g -I../../include

SRC		= ft_abs.c					\
		  ft_absd.c					\
		  ft_absf.c					\
		  ft_approximatelyd.c		\
		  ft_approximatelyf.c		\
		  ft_clamp_0_1.c			\
		  ft_clamp.c				\
		  ft_clampd_0_1.c			\
		  ft_clampd.c				\
		  ft_clampf_0_1.c			\
		  ft_clampf.c				\
		  ft_delta_angled.c			\
		  ft_delta_anglef.c			\
		  ft_digits.c				\
		  ft_expd.c					\
		  ft_expf.c					\
		  ft_factorial.c			\
		  ft_gammad.c				\
		  ft_gammaf.c				\
		  ft_gaussian_kerneld.c 	\
		  ft_gaussian_kernelf.c		\
		  ft_lerpd_angle.c			\
		  ft_lerpd_unclamped.c		\
		  ft_lerpd.c				\
		  ft_lerpf_angle.c			\
		  ft_lerpf_unclamped.c		\
		  ft_lerpf.c				\
		  ft_logd.c					\
		  ft_logf.c					\
		  ft_max.c					\
		  ft_maxd.c					\
		  ft_maxf.c					\
		  ft_min.c					\
		  ft_mind.c					\
		  ft_minf.c					\
		  ft_mod.c					\
		  ft_modd.c					\
		  ft_modf.c					\
		  ft_move_towards_angled.c	\
		  ft_move_towards_anglef.c	\
		  ft_move_towards.c			\
		  ft_move_towardsd.c		\
		  ft_move_towardsf.c		\
		  ft_pow.c					\
		  ft_powd.c					\
		  ft_powf.c					\
		  ft_rsqrtd.c				\
		  ft_rsqrtf.c				\
		  ft_sign.c					\
		  ft_signd.c				\
		  ft_signf.c				\
		  ft_smooth_stepd.c			\
		  ft_smooth_stepf.c			\
		  ft_sqrtd.c				\
		  ft_sqrtf.c

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