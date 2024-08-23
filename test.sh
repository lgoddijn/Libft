clear

cc -Wall -Wextra -Werror -Wpedantic -std=gnu17 -fstack-protector-strong -O0 -g memcpy.s test.c &> /dev/null

echo "Using -O0 optimization flag..."

./a.out

echo "\n"

cc -Wall -Wextra -Werror -Wpedantic -std=gnu17 -fstack-protector-strong -O1 -g memcpy.s test.c &> /dev/null

echo "Using -O1 optimization flag..."

./a.out

echo "\n"

cc -Wall -Wextra -Werror -Wpedantic -std=gnu17 -fstack-protector-strong -O2 -g memcpy.s test.c &> /dev/null

echo "Using -O2 optimization flag..."

./a.out

echo "\n"

cc -Wall -Wextra -Werror -Wpedantic -std=gnu17 -fstack-protector-strong -O3 -g memcpy.s test.c &> /dev/null

echo "Using -O3 optimization flag..."

./a.out

echo "\n"

cc -Wall -Wextra -Werror -Wpedantic -std=gnu17 -fstack-protector-strong -Ofast -g memcpy.s test.c &> /dev/null

echo "Using -Ofast optimization flag..."

./a.out
