# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/31 16:07:03 by lgoddijn          #+#    #+#              #
#    Updated: 2024/08/26 17:57:56 by lgoddijn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= unistd.a

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -Wstrict-prototypes		\
		  -Wmissing-prototypes -Wpedantic -std=gnu17	\
		  -fstack-protector-strong -O2 -g -I../../include

SRC		= ft_write.c		\
		  ft_open.c			\
		  ft_read.c			\
		  ft_close.c   		\
		  ft_access.c		\
		  ft_alarm.c		\
		  ft_chmod.c		\
		  ft_chown.c		\
		  ft_chdir.c		\
		  ft_dup.c			\
		  ft_dup2.c			\
		  ft_execve.c		\
		  ft_exit_group.c	\
		  ft_exit.c			\
		  ft_fchdir.c		\
		  ft_fchown.c		\
		  ft_fdatasync.c	\
		  ft_fsync.c		\
		  ft_getcwd.c		\
		  ft_getegid.c		\
		  ft_geteuid.c		\
		  ft_getgid.c		\
		  ft_getgroups.c	\
		  ft_gethostname.c	\
		  ft_getpgid.c		\
		  ft_getpgrp.c		\
		  ft_getpid.c		\
		  ft_getppid.c		\
		  ft_getsid.c		\
		  ft_gettid.c		\
		  ft_getuid.c		\
		  ft_lchown.c		\
		  ft_link.c			\
		  ft_lseek.c		\
		  ft_mkdir.c		\
		  ft_pause.c		\
		  ft_pipe.c			\
		  ft_rmdir.c		\
		  ft_symlink.c		\
		  ft_sync.c			\
		  ft_waitpid.c		\
		  ft_wait.c			\
		  ft_readlink.c

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