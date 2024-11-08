/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:52:45 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:07:15 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_memory.h"

static __always_inline void	*__fwd_move(
		const char *s, char *d, size_t n, void *dst)
{
	if ((uintptr_t)s % sizeof(t_wt) == (uintptr_t)d % sizeof(t_wt))
	{
		while ((uintptr_t)d % sizeof(t_wt))
		{
			if (!n--)
				return (*dst);
			*d++ = *s++;
		}
		while (n >= sizeof(t_wt))
		{
			*(t_wt *)d = *(t_wt *)s;
			n -= sizeof(t_wt);
			d += sizeof(t_wt);
			s += sizeof(t_wt);
		}
	}
	while (n--)
		*d++ = *s++;
	return (dst);
}

static __always_inline void	*__bwd_move(
		const char *s, char *d, size_t n, void *dst)
{
	if ((uintptr_t)s % sizeof(t_wt) == (uintptr_t)d % sizeof(t_wt))
	{
		while ((uintptr_t)(d + n) % sizeof(t_wt))
		{
			if (!n--)
				return (dest);
			d[n] = s[n];
		}
		while (n >= sizeof(t_wt))
		{
			n -= sizeof(t_wt);
			*(t_wt *)(d + n) = *(t_wt *)(s + n);
		}
	}
	while (n--)
		d[n] = s[n];
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	const char	*s = src;
	char		*d;

	d = dst;
	if (d == s || !dst || !src)
		return (d);
	if ((uintptr_t)s - (uintptr_t)d - n <= -2 * n)
		return (ft_memcpy(d, s, n));
	if (d < s)
		return (__fwd_move(s, d, n, dst));
	return (__bwd_move(s, d, n, dst));
}
