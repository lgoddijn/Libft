# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/31 17:00:18 by lgoddijn          #+#    #+#              #
#    Updated: 2024/07/16 19:04:35 by lgoddijn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= linked_list.a

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -Wstrict-prototypes		\
		  -Wmissing-prototypes -Wpedantic -std=gnu17	\
		  -fstack-protector-strong -O2 -g -I../../include

SRC		= ft_append_lst.c	\
		  ft_clear_lst.c	\
		  ft_pop_lst.c		\
		  ft_init_lst.c		\
		  ft_iter_lst.c		\
		  ft_last_lst.c		\
		  ft_map_lst.c		\
		  ft_prepend_lst.c	\
		  ft_size_lst.c

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