# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/31 17:28:57 by lgoddijn          #+#    #+#              #
#    Updated: 2024/07/16 19:03:15 by lgoddijn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= dictionary.a

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -Wstrict-prototypes		\
		  -Wmissing-prototypes -Wpedantic -std=gnu17	\
		  -fstack-protector-strong -O2 -g -I../../include

SRC		= ft_access_dict.c	\
		  ft_append_dict.c	\
		  ft_clear_dict.c	\
		  ft_pop_dict.c		\
		  ft_init_dict.c	\
		  ft_iter_dict.c	\
		  ft_last_dict.c	\
		  ft_map_dict.c		\
		  ft_prepend_dict.c	\
		  ft_search_dict.c	\
		  ft_size_dict.c

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