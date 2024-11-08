/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stpncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:56:36 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/08 21:58:21 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

static __always_inline void	__do_da_funky_loop(
		const t_word *ws, t_word *wd, size_t *n)
{
	while (*n >= sizeof(size_t)
		&& !((*ws) - ((size_t) - 1 / UCHAR_MAX)
			& ~(*ws) & ((size_t) - 1 / UCHAR_MAX)
			* (UCHAR_MAX / 2 + 1)))
	{
		*wd = *ws;
		++ws;
		++wd;
		*n -= sizeof(size_t);
	}
}

static __always_inline int	__do_cpy_align(
		char *__restrict__ d, const char *__restrict__ s, size_t *n)
{
	while ((uintptr_t)s & sizeof(size_t) - 1 && *n)
	{
		*d = *s;
		(*n)--;
		++s;
		++d;
	}
	if (!*n || !*s)
	{
		ft_memset(d, 0, *n);
		return (1);
	}
	return (0);
}

char	*ft_stpncpy(char *__restrict__ d, const char *__restrict__ s, size_t n)
{
	const t_word	*ws;
	t_word			*wd;

	if (((uintptr_t)s & sizeof(size_t) - 1) == (
			(uintptr_t)d & sizeof(size_t) - 1))
	{
		if (__do_cpy_align(d, s, &n))
			return (d);
		wd = (void *)d;
		ws = (const void *)s;
		__do_da_funky_loop(ws, wd, &n);
		d = (void *)wd;
		s = (const void *)ws;
	}
	while (n)
	{
		*d = *s;
		--n;
		++s;
		++d;
	}
	ft_memset(d, 0, n);
	return (d);
}
