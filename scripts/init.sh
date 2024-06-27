#!/bin/bash

# Takes optional commandline argument for target path.
# Otherwise defaults to current working directory.
# Will clone most the most recent libft state.
# Will remove the .git directory to avoid conflicts.

# Will create a default makefile for the project
# Bonus rules or MLX dependencies have to be done manually.
# 42 Header has to be added manually as well.

TARGET_DIR=$(eval realpath ${1:-$(pwd)})

mkdir -p $TARGET_DIR/Libft/

REPO_URL="https://github.com/lgoddijn/Libft.git"

git clone $REPO_URL $TARGET_DIR/Libft/

rm -rf $TARGET_DIR/Libft/.git

echo "Cloned Libft into $TARGET_DIR/Libft/"

MAKEFILE_CONTENT="\
TARGET  = 

CC      = cc

CFLAGS  = 

SRCS    = 

OBJS    = \$(SRCS:.c=.o)

HEADER  = 

%.o: %.c \$(HEADER)
	\$(CC) \$(CFLAGS) -c \$< -o \$@

all: \$(TARGET)

\$(TARGET): \$(OBJS)
	@make -C ./Libft
	\$(CC) \$(OBJS) ./Libft/bin/Libft.a -Iinclude -ldl -lglfw -pthread -lm -o \$(TARGET)

clean:
	@make clean -C ./Libft
	@rm -f \$(OBJS)

fclean: clean
	@make fclean -C ./Libft
	@rm -f \$(TARGET)

re: fclean all

.PHONY: all clean fclean re
"

echo "$MAKEFILE_CONTENT" > $TARGET_DIR/Makefile

echo "Makefile has been generated successfully."
