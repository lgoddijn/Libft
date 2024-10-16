# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 01:59:10 by lgoddijn          #+#    #+#              #
#    Updated: 2024/10/16 02:00:14 by lgoddijn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= dirent.a

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -Wstrict-prototypes		\
		  -Wmissing-prototypes -Wpedantic -std=gnu17	\
		  -fstack-protector-strong -O2 -g -I../../include

SRC		= ft_alphasort.c		\
		  ft_closedir.c			\
		  ft_fdopendir.c		\
		  ft_opendir.c			\
		  ft_posix_getdents.c	\
		  ft_readdir_r.c		\
		  ft_readdir.c			\
		  ft_rewinddir.c		\
		  ft_scandir.c			\
		  ft_seekdir.c

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