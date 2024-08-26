clear

clang -Wall -Wextra -Werror -Wpedantic -std=gnu17 -fstack-protector-strong -O2 -g memcpy.s testmemcpy.c &> /dev/null

echo "Using -O2 optimization flag..."

./a.out
