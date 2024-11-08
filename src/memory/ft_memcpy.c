/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:50:53 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/08/26 18:13:49 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_memory.h"

/*

@def
	`ft_memcpy.c : ft_memcpy`

@brief
	Copies n bytes from a source to a destination.

@man
	The memcpy() function copies n bytes
	from memory area src to memory area dest.
	The memory areas must not overlap.
	Use memmove(3) if the memory areas do overlap.

@synopsis
	`void	*ft_memcpy(void *dest, const void *src, size_t n)`

@params
	`void *dest` The destination buffer for n bytes to be copied into.
	`const void *src` The constant source buffer.
	`size_t n` The number of bytes that should be copied from src to dest.

@return
	`void *` The `dest` pointer (regardless of failure).

@notes
	Because the void ptr buffer is of type `T` we simply
	cast the pointer to an `unsigned char` aka. `int`
	this allows the function to go through the memory without type issues.

	However the function should cast the return back to `void *`.

	`const *ptr` will only make the pointer constant, not the value.

	This function, by design, should check the `dest` and `src` arguments.
	It should also NOT be used when the memory areas overlap.
	If they do just use `ft_memmove` instead.

	The `memcpy` has undefined behavior when either buffer is `NULL`.
	So it is designed to crash or return `dest` at all times.
	However since I improved upon the function. It is vital that
	the function does not return `NULL` when either buffer is `NULL`.
	Instead it should always return `dest` even when handling errors.

	The function also uses pointer arithmetics instead of indexes.
	Since the function is the foundation of a lot of others,
	This small decision will affect a large efficiency factor.

*/

static __always_inline void	__aligned_cpy_loop(
		const unsigned char *s,
		unsigned char *d,
		size_t *n)
{
	while (*n >= 16)
	{
		*(t_u32 *)(d + 0) = *(t_u32 *)(s + 0);
		*(t_u32 *)(d + 4) = *(t_u32 *)(s + 4);
		*(t_u32 *)(d + 8) = *(t_u32 *)(s + 8);
		*(t_u32 *)(d + 12) = *(t_u32 *)(s + 12);
		s += 16;
		d += 16;
		*n -= 16;
	}
}

static __always_inline void	*__do_aligned_blocks(
		const unsigned char *s,
		unsigned char *d,
		void *__restrict__ dst,
		size_t n)
{
	__aligned_cpy_loop(s, d, &n);
	if (n & 8)
	{
		*(t_u32 *)(d + 0) = *(t_u32 *)(s + 0);
		*(t_u32 *)(d + 4) = *(t_u32 *)(s + 4);
		d += 8;
		s += 8;
	}
	if (n & 4)
	{
		*(t_u32 *)(d + 0) = *(t_u32 *)(s + 0);
		d += 4;
		s += 4;
	}
	if (n & 2)
	{
		*d++ = *s++;
		*d++ = *s++;
	}
	if (n & 1)
		*d = *s;
	return (dst);
}

static __always_inline void	*__do_final_alignment(
		const unsigned char *s,
		unsigned char *d,
		void *__restrict__ dst,
		size_t n)
{
	register int	i;

	i = 16;
	if (n & 16)
		while (i--)
			*d++ = *s++;
	i = 8;
	if (n & 8)
		while (i--)
			*d++ = *s++;
	i = 4;
	if (n & 4)
		while (i--)
			*d++ = *s++;
	i = 2;
	if (n & 2)
		while (i--)
			*d++ = *s++;
	if (n & 1)
		*d = *s;
	return (dst);
}

static __always_inline void	__shift_offset_align(
		const unsigned char *s,
		unsigned char *d,
		size_t *n,
		off_t off)
{
	register uint32_t	w;
	register uint32_t	x;

	if (off < 1 || off > 3)
		return ;
	w = *(t_u32 *)s;
	*d++ = *s++;
	*d++ = *s++;
	*d++ = *s++;
	*n -= 4 - off;
	while (*n >= 16 + off)
	{
		x = *(t_u32 *)(s + 1);
		*(t_u32 *)(d + 0) = (w >> (32 - 8 * off)) | (x << (off * 8));
		w = *(t_u32 *)(s + 5);
		*(t_u32 *)(d + 4) = (x >> (32 - 8 * off)) | (w << (off * 8));
		x = *(t_u32 *)(s + 9);
		*(t_u32 *)(d + 8) = (w >> (32 - 8 * off)) | (x << (off * 8));
		w = *(t_u32 *)(s + 13);
		*(t_u32 *)(d + 12) = (x >> (32 - 8 * off)) | (w << (off * 8));
		s += 16;
		d += 16;
		*n -= 16;
	}
}

void	*ft_memcpy(
	void *__restrict__ dst,
	const void *__restrict__ src,
	size_t n)
{
	register const unsigned char	*s = src;
	register unsigned char			*d;

	if (!dst || !src)
		return (dst);
	d = dst;
	while ((uintptr_t)s % 4 && n--)
		*d++ = *s++;
	if ((uintptr_t)d % 4 == 0)
		return (__do_aligned_blocks(s, d, dst, n));
	if (n < 32)
	{
		while (n--)
			*d++ = *s++;
		return (dst);
	}
	__shift_offset_align(s, d, n, (uintptr_t)d % 4);
	return (__do_final_alignment(s, d, dst, n));
}
