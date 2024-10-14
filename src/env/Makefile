# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/31 12:28:07 by lgoddijn          #+#    #+#              #
#    Updated: 2024/10/14 17:19:15 by lgoddijn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= env.a

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -Wstrict-prototypes		\
		  -Wmissing-prototypes -Wpedantic -std=gnu17	\
		  -fstack-protector-strong -O2 -g -I../../include

SRC		= __env_rm_add.c	\
		  __envp_rm_add.c	\
		  ft_getenv.c		\
		  ft_getenvp.c		\
		  ft_putenv.c		\
		  ft_putenvp.c		\
		  ft_setenv.c		\
		  ft_setenvp.c		\
		  ft_unsetenv.c		\
		  ft_unsetenvp.c	\
		  ft_clearenv.c		\
		  ft_clearenvp.c

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