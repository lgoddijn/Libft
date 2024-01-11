# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/31 17:38:38 by lgoddijn          #+#    #+#              #
#    Updated: 2024/01/11 17:24:46 by lgoddijn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= heap.a

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -Wstrict-prototypes		\
		  -Wmissing-prototypes -Wpedantic -std=c99		\
		  -fstack-protector-strong -O2 -g -I../../include

SRC		= ft_mmap.c		\
		  ft_calloc.c	\
		  ft_realloc.c	\
		  ft_free2d.c

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