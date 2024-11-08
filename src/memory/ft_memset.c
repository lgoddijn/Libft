/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:51:26 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/08 20:18:45 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_memory.h"

/*
	Fill head and tail with minimal branching. Each
	conditional ensures that all the subsequently used
	offsets are well-defined and in the dst region.

	Advance pointer to align it at a 4-byte boundary,
	and truncate n to a multiple of 4. Already took care
	of any head/tail that get cut off by the alignment.
*/
static __always_inline int	__fill_bounds_align(
		unsigned char *s, int c, size_t *n)
{
	register size_t	k;

	if (!*n)
		return (1);
	s[0] = c;
	s[*n - 1] = c;
	if (*n <= 2)
		return (1);
	s[1] = c;
	s[2] = c;
	s[*n - 2] = c;
	s[*n - 3] = c;
	if (*n <= 6)
		return (1);
	s[3] = c;
	s[*n - 4] = c;
	if (*n <= 8)
		return (1);
	k = -(uintptr_t)s & 3;
	s += k;
	*n -= k;
	*n &= -4;
	return (0);
}

/*
	In preparation to copy 32 bytes at a time, aligned on
	an 8-byte bounary, fill head/tail up to 28 bytes each.
	As in the initial byte-based head/tail fill, each
	conditional below ensures that the subsequent offsets
	are valid (e.g. !(n<=24) implies n>=28).
*/
static __always_inline int	__pad_buffer_align(
		unsigned char *s, size_t n, t_u32 c32)
{
	*(t_u32 *)(s + 0) = c32;
	*(t_u32 *)(s + n - 4) = c32;
	if (n <= 8)
		return (1);
	*(t_u32 *)(s + 4) = c32;
	*(t_u32 *)(s + 8) = c32;
	*(t_u32 *)(s + n - 12) = c32;
	*(t_u32 *)(s + n - 8) = c32;
	if (n <= 24)
		return (1);
	*(t_u32 *)(s + 12) = c32;
	*(t_u32 *)(s + 16) = c32;
	*(t_u32 *)(s + 20) = c32;
	*(t_u32 *)(s + 24) = c32;
	*(t_u32 *)(s + n - 28) = c32;
	*(t_u32 *)(s + n - 24) = c32;
	*(t_u32 *)(s + n - 20) = c32;
	*(t_u32 *)(s + n - 16) = c32;
	return (0);
}

/*
	If this loop is reached, 28 tail bytes have already been
	filled, so any remainder when n drops below 32 can be ignored.
*/
static __always_inline void	__do_final_loop(
		unsigned char *s, t_u64 c64, size_t n)
{
	while (n >= 32)
	{
		*(t_u64 *)(s + 0) = c64;
		*(t_u64 *)(s + 8) = c64;
		*(t_u64 *)(s + 16) = c64;
		*(t_u64 *)(s + 24) = c64;
		n -= 32;
		s += 32;
	}
}

void	*ft_memset(void *dst, int c, size_t n)
{
	register t_u32			c32;
	register t_u64			c64;
	register unsigned char	*s;
	register size_t			k;

	if (!dst)
		return (dst);
	s = dst;
	if (__fill_bounds_align(s, c, &n))
		return (dst);
	c32 = ((t_u32) - 1) / 255 * (unsigned char)c;
	if (__pad_buffer_align(s, n, c32))
		return (dst);
	c64 = c32 | ((t_u64)c32 << 32);
	k = 24 + ((uintptr_t)s & 4);
	s += k;
	n -= k;
	__do_final_loop(s, c64, n);
	return (dst);
}
