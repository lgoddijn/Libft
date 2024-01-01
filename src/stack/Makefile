# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/31 17:53:56 by lgoddijn          #+#    #+#              #
#    Updated: 2023/12/31 17:55:40 by lgoddijn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= stack.a

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -Wstrict-prototypes		\
		  -Wmissing-prototypes -Wpedantic -std=c99		\
		  -fstack-protector-strong -O2 -g -I../../include

SRC		= ft_init_stack.c		\
		  ft_is_empty_stack.c	\
		  ft_is_full_stack.c	\
		  ft_peek_stack.c		\
		  ft_pop_stack.c		\
		  ft_push_stack.c		\
		  ft_free_stack.c

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