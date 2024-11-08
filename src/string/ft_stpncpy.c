/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stpncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:56:36 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/07 17:44:56 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

static __always_inline void	__do_da_funky_loop(
		const t_word *ws, t_word *wd, size_t *n)
{
	wd = (void *)d;
	ws = (const void *)s;
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

char	*ft_stpncpy(char *__restrict__ d, const char *__restrict__ s, size_t n)
{
	const t_word	*ws;
	t_word			*wd;

	if (((uintptr_t)s & sizeof(size_t) - 1) == (
			(uintptr_t)d & sizeof(size_t) - 1))
	{
		while ((uintptr_t)s & sizeof(size_t) - 1 && n--)
		{
			*d = *s;
			++s;
			++d;
		}
		if (!n || !*s)
		{
			ft_memset(d, 0, n);
			return (d);
		}
		__do_da_funky_loop(ws, wd, &n);
		d = (void *)wd;
		s = (const void *)ws;
	}
	while (n-- && ++s && ++d)
		*(d - 1) = *(s - 1);
	ft_memset(d, 0, n);
	return (d);
}
