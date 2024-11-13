# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 20:24:33 by lgoddijn          #+#    #+#              #
#    Updated: 2024/11/11 20:46:18 by lgoddijn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= misc.a

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -Wstrict-prototypes		\
		  -Wmissing-prototypes -Wpedantic -std=gnu17	\
		  -fstack-protector-strong -O2 -g -I../../include

SRC		= frpath/__frpath_abspath.c		\
		  frpath/__frpath_readlink.c	\
		  frpath/__frpath_end.c			\
		  frpath/__frpath_init.c		\
		  frpath/__frpath_loop.c		\
		  frpath/__frpath.c				\
		  ft_atexit.c

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