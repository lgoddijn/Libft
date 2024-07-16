# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 14:44:40 by lgoddijn          #+#    #+#              #
#    Updated: 2024/07/16 19:06:10 by lgoddijn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET		= bin/Libft.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Wstrict-prototypes		\
			  -Wmissing-prototypes -Wpedantic -std=gnu17	\
			  -fstack-protector-strong -O2 -g -I../../include

SUBMODULES	= src/dictionary	\
			  src/file			\
			  src/heap			\
			  src/internal		\
			  src/linked_list	\
			  src/math			\
			  src/memory		\
			  src/print			\
			  src/stack			\
			  src/string		\
			  src/unistd		\
			  src/vector

LIBFILES = $(foreach submodule,$(SUBMODULES), \
		   $(submodule)/$(notdir $(submodule)).a)

all: $(SUBMODULES) $(TARGET)

$(SUBMODULES):
	$(MAKE) -C $@

$(TARGET): $(LIBFILES)
	@echo "Combining Libraries..."
	mkdir -p bin
	rm -f *.o
	for libfile in $(LIBFILES); do \
		ar x $$libfile; \
	done
	ar crs $@ *.o
	rm -f *.o
	@echo "Build Succeeded."

clean:
	for dir in $(SUBMODULES); do \
		$(MAKE) -C $$dir clean; \
	done

fclean: clean
	rm -f $(TARGET) *.o
	rm -rf bin

re: clean all

.PHONY: all clean $(SUBMODULES) re fclean
