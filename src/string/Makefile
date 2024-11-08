# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/31 16:10:45 by lgoddijn          #+#    #+#              #
#    Updated: 2024/07/19 11:56:27 by lgoddijn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= string.a

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -Wstrict-prototypes		\
		  -Wmissing-prototypes -Wpedantic -std=gnu17	\
		  -fstack-protector-strong -O2 -g -I../../include

SRC		= ft_atod.c				\
		  ft_atof.c				\
		  ft_atoi.c				\
		  ft_atol.c				\
		  ft_atox.c				\
		  ft_isalnum.c			\
		  ft_isalpha.c			\
		  ft_isascii.c			\
		  ft_isdigit.c			\
		  ft_isfloat.c			\
		  ft_isint.c			\
		  ft_isprint.c			\
		  ft_isspace.c			\
		  ft_itoa.c				\
		  ft_stpncpy.c			\
		  ft_strncpy.c			\
		  ft_strsep.c			\
		  ft_strsplit.c			\
		  ft_strchr.c			\
		  ft_strdup.c			\
		  ft_striteri.c			\
		  ft_strequals.c		\
		  ft_strjoin.c			\
		  ft_strlcat.c			\
		  ft_strlcpy.c			\
		  ft_strlen.c			\
		  ft_strnlen.c			\
		  ft_strmapi.c			\
		  ft_strcmp.c			\
		  ft_strncmp.c			\
		  ft_strnequals.c		\
		  ft_strnstr.c			\
		  ft_strrchr.c			\
		  ft_strtrim.c			\
		  ft_substr.c			\
		  ft_tolower.c			\
		  ft_toupper.c			\
		  ft_strnjoin.c			\
		  ft_strchrnul.c		\
		  ft_strpbrk.c			\
		  ft_swapcase.c			\
		  ft_strspn.c			\
		  ft_strcspn.c			\
		  ft_strtok.c			\
		  ft_strtok_r.c			\
		  ft_strstartswith.c	\
		  ft_strendswith.c		\

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