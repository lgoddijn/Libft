# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/31 16:10:45 by lgoddijn          #+#    #+#              #
#    Updated: 2024/02/02 19:05:37 by lgoddijn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= string.a

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -Wstrict-prototypes		\
		  -Wmissing-prototypes -Wpedantic -std=c99		\
		  -fstack-protector-strong -O2 -g -I../../include

SRC		= ft_atoi.c			\
		  ft_isalnum.c		\
		  ft_isalpha.c		\
		  ft_isascii.c		\
		  ft_isdigit.c		\
		  ft_isprint.c		\
		  ft_itoa.c			\
		  ft_strsplit.c		\
		  ft_strchr.c		\
		  ft_strdup.c		\
		  ft_striteri.c		\
		  ft_strequals.c	\
		  ft_strjoin.c		\
		  ft_strlcat.c		\
		  ft_strlcpy.c		\
		  ft_strlen.c		\
		  ft_strmapi.c		\
		  ft_strcmp.c		\
		  ft_strncmp.c		\
		  ft_strnstr.c		\
		  ft_strrchr.c		\
		  ft_strtrim.c		\
		  ft_substr.c		\
		  ft_tolower.c		\
		  ft_toupper.c		\
		  ft_strnjoin.c

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