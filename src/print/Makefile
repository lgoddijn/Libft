# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/31 17:10:45 by lgoddijn          #+#    #+#              #
#    Updated: 2024/07/16 19:05:19 by lgoddijn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= print.a

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -Wstrict-prototypes		\
		  -Wmissing-prototypes -Wpedantic -std=gnu17	\
		  -fstack-protector-strong -O2 -g -I../../include

SRC		= ft_print_char.c	\
		  ft_print_str.c	\
		  ft_print_uint.c	\
		  ft_print_int.c	\
		  ft_print_ptr.c	\
		  ft_print_hex.c	\
		  ft_printf.c		\
		  ft_raise.c

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