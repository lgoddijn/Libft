# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/31 14:00:49 by lgoddijn          #+#    #+#              #
#    Updated: 2024/07/31 13:10:24 by lgoddijn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= internal.a

SRC		= __syscall.c

CFLAGS	= -Wall -Wextra -Werror -Wstrict-prototypes		\
		  -Wmissing-prototypes -Wpedantic -std=gnu17	\
		  -fstack-protector-strong -O2 -g -I../../include

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