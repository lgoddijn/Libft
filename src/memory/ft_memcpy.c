/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:50:53 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/11 22:15:47 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_memory.h"

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

	w = *(t_u32 *)s;
	while (*n-- >= (size_t)(4 - off))
		*d++ = *s++;
	while (*n >= (size_t)(16 + off))
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
	while ((uintptr_t)s % 4 && n)
	{
		*d++ = *s++;
		--n;
	}
	if ((uintptr_t)d % 4 == 0)
		return (__do_aligned_blocks(s, d, dst, n));
	if (n < 32)
	{
		while (n--)
			*d++ = *s++;
		return (dst);
	}
	__shift_offset_align(s, d, &n, (uintptr_t)d % 4);
	return (__do_final_alignment(s, d, dst, n));
}
