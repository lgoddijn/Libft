/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:50:05 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/08/23 18:21:52 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

#define ITER	100000000
#define BUFSIZE	4096 * 4

__always_inline size_t	ft_strlen(const char *__restrict__ s)
{
#if defined(__GNUC__) // GNUC needed for builtins
	typedef unsigned long int __attribute__ ((__may_alias__)) word_t;
	typedef unsigned long int __attribute__ ((__may_alias__)) bytemask_t;

	register const uintptr_t	s0 = (uintptr_t)s;
	register const word_t		*w = (const word_t *)(((uintptr_t)s) & \
									-((uintptr_t)(sizeof(word_t))));

	register word_t	wi = *w;

	register word_t	m = ((word_t)-1 / 0xff) * 0x7f;

#if __BYTE_ORDER == __LITTLE_ENDIAN
	bytemask_t	register mask = ~(((wi & m) + m) | wi | m) >> (CHAR_BIT * (s0 % sizeof (word_t)));
#else
	bytemask_t	register mask = ~(((wi & m) + m) | wi | m) << (CHAR_BIT * (s0 % sizeof (word_t)));
#endif

	if (mask)
	{
#if __BYTE_ORDER == __LITTLE_ENDIAN
# if __SIZEOF_POINTER__ == 8
		return (__builtin_ctzl(mask) / CHAR_BIT);
# else
		return (__builtin_ctzll(mask) / CHAR_BIT);
# endif
#else
# if __SIZEOF_POINTER__ == 8
		return (__builtin_clzl(mask) / CHAR_BIT);
# else
		return (__builtin_clzll(mask) / CHAR_BIT);
# endif
#endif
	}

	do
	{
		wi = *++w;
	} while (((wi - (((word_t)-1 / 0xff) * 0x01)) & ~wi & (((word_t)-1 / 0xff) * 0x80)) == 0);

#if __BYTE_ORDER == __LITTLE_ENDIAN
	wi = (wi - ((word_t)-1 / 0xff) * 0x01) & ~wi & ((word_t)-1 / 0xff) * 0x80;
#else
	word_t rb = ((word_t)-1 / 0xff) * 0x7f;
	wi = ~(((wi & rb) + rb) | wi | rb);
#endif

#if __BYTE_ORDER == __LITTLE_ENDIAN
# if __SIZEOF_POINTER__ == 8
		wi = (__builtin_ctzl(wi) / CHAR_BIT);
# else
		wi = (__builtin_ctzll(wi) / CHAR_BIT);
# endif
#else
# if __SIZEOF_POINTER__ == 8
		wi = (__builtin_clzl(wi) / CHAR_BIT);
# else
		wi = (__builtin_clzll(wi) / CHAR_BIT);
# endif
#endif

	return ((const char *)w) + wi - s;
#endif
}

size_t ft_strlen2(const char *s)
{
	const char *s0 = s;
#if defined(__GNUC__) // GNUC needed for builtins
	const size_t __attribute__((__may_alias__)) *w;
	for (; (uintptr_t)s % sizeof(size_t); ++s)
		if (!*s) return (s - s0);
	for (w = (const void *)s;
		!((*w) - ((size_t)-1 / UCHAR_MAX) &
		~(*w) & (((size_t)-1 / UCHAR_MAX) *
		(UCHAR_MAX / 2 + 1))); ++w);
	s = (const void *)w;
#endif
	for (; *s; ++s);
	return (s - s0);
}


size_t	ft_strlen3(const char *s)
{
	const char	*s0 = s;

	while (*s++);
	return (size_t)(s - s0);
}

size_t	ft_strlen4(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

void benchmark_strlen(const char *buf)
{
	clock_t start, end;
	double t1, t2, t3, t4, t5;
	size_t i;

	start = clock();
	for (i = 0; i < ITER; ++i)
		(void)strlen(buf);
	end = clock();
	t1 = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
	printf("glibc's strlen took %fms\n", t1);

	start = clock();
	for (i = 0; i < ITER; ++i)
		(void)ft_strlen(buf);
	end = clock();
	t2 = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
	printf("Luca's strlen took %fms\n", t2);

	start = clock();
	for (i = 0; i < ITER; ++i)
		(void)ft_strlen2(buf);
	end = clock();
	t3 = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
	printf("Luca's previous strlen took %fms\n", t3);

	start = clock();
	for (i = 0; i < ITER; ++i)
		(void)ft_strlen3(buf);
	end = clock();
	t4 = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
	printf("L strlen took %fms\n", t4);

	start = clock();
	for (i = 0; i < ITER; ++i)
		(void)ft_strlen4(buf);
	end = clock();
	t5 = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
	printf("Super L strlen took %fms\n", t5);
}

void
do_test (void)
{
	static const size_t lens[] = { 0, 1, 0, 2, 0, 1, 0, 3,
					0, 1, 0, 2, 0, 1, 0, 4 };
	char basebuf[24 + 32];
	size_t base;

	for (base = 0; base < 32; ++base)
	{
		char *buf = basebuf + base;
		size_t words;

		for (words = 0; words < 4; ++words)
		{
			size_t last;
			memset (buf, 'a', words * 4);

			for (last = 0; last < 16; ++last)
			{
				buf[words * 4 + 0] = (last & 1) != 0 ? 'b' : '\0';
				buf[words * 4 + 1] = (last & 2) != 0 ? 'c' : '\0';
				buf[words * 4 + 2] = (last & 4) != 0 ? 'd' : '\0';
				buf[words * 4 + 3] = (last & 8) != 0 ? 'e' : '\0';
				buf[words * 4 + 4] = '\0';

				if (ft_strlen(buf) != (size_t)(words * 4 + lens[last]))
				{
					printf ("ft_strlen failed for base=%zu, words=%zu, and last=%zu (is %zd, expected %zd)\n",
					base, words, last,
					ft_strlen (buf), words * 4 + lens[last]);
					return;
				}
			}
		}
	}
	return;
}


int32_t main(void)
{
	printf("Benchmarking over %d iterations with %d bytes per iteration.\n", ITER, BUFSIZE);

	int32_t	fd = open("/dev/urandom", O_RDONLY);

	if (fd == -1)
		return (1);

	char *buf = (char *)malloc(BUFSIZE + 1);
	if (!buf)
	{
		close(fd);
		return (1);
	}

	ssize_t bytes_read = read(fd, buf, BUFSIZE);
	if (bytes_read != BUFSIZE)
	{
		close(fd);
		free(buf);
		return (1);
	}
	buf[bytes_read] = '\0';

	benchmark_strlen(buf);

	free(buf);
	close(fd);

	do_test();

	return (0);
}
