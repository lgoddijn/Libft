# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/31 15:52:56 by lgoddijn          #+#    #+#              #
#    Updated: 2024/07/18 20:24:26 by lgoddijn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= memory.a

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -Wstrict-prototypes		\
		  -Wmissing-prototypes -Wpedantic -std=gnu17	\
		  -fstack-protector-strong -O2 -g -I../../include

SRC		= ft_bzero.c		\
		  ft_memchr.c		\
		  ft_memcmp.c 		\
		  ft_memcpy.c		\
		  ft_memmove.c		\
		  ft_memset.c		\
		  ft_memequals.c	\

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