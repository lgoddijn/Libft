# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/31 14:00:49 by lgoddijn          #+#    #+#              #
#    Updated: 2024/01/01 22:08:09 by lgoddijn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= internal.a
SRC		= ft_syscall.s
OBJ		= $(SRC:.s=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $(OBJ)

.s.o:
	as $< -o $@

clean:
	rm -f $(OBJ) $(NAME)

re: clean all

.PHONY: all clean re