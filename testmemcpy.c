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

#define ITER	100000
#define BUFSIZE	4096 * 4

typedef unsigned char	t_byte;

#define OPSIZ	sizeof(unsigned long int __attribute__ ((__may_alias__)));

static __always_inline	__cpy_fwd(byte_t *__restrict__ dst, const byte_t *__restrict__ src, size_t n)
{
	while (n > 0)
	{
		*dst = *src;
		++src;
		++dst;
		--n;
	}
}

void	*ft_memcpy2(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr1;
	const unsigned char	*ptr2;

	ptr1 = (unsigned char *)dest;
	ptr2 = (const unsigned char *)src;
	while (n--)
		*ptr1++ = *ptr2++;
	return (dest);
}

void benchmark_memcpy(void *__restrict__ dst, const void *__restrict__ src, size_t n)
{
	clock_t start, end;
	double t1, t2, t3;

	start = clock();
	for (int i = 0; i < ITER; ++i)
		(void)memcpy(dst, src, n);
	end = clock();
	t1 = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
	printf("glibc's memcpy took %fms\n", t1);

	start = clock();
	for (int i = 0; i < ITER; ++i)
		(void)ft_memcpy(dst, src, n);
	end = clock();
	t2 = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
	printf("Luca's memcpy took %fms\n", t2);

	start = clock();
	for (int i = 0; i < ITER; ++i)
		(void)ft_memcpy2(dst, src, n);
	end = clock();
	t3 = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
	printf("Old memcpy took %fms\n", t3);
}

int32_t main(void)
{
	printf("Benchmarking over %d iterations with %d bytes per iteration.\n", ITER, BUFSIZE);

	int32_t	fd = open("/dev/urandom", O_RDONLY);

	if (fd == -1)
		return (1);

	char *src = (char *)malloc(BUFSIZE + 1);
	if (!src)
	{
		close(fd);
		return (1);
	}

	ssize_t bytes_read = read(fd, src, BUFSIZE);
	if (bytes_read != BUFSIZE)
	{
		close(fd);
		free(src);
		return (1);
	}
	src[bytes_read] = '\0';

	char *dst = (char *)malloc(BUFSIZE + 1);

	if (!dst)
	{
		close(fd);
		free(src);
		return (1);
	}

	benchmark_memcpy(dst, src, BUFSIZE);

	free(dst);
	free(src);
	close(fd);

	return (0);
}
