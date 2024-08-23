/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:46:43 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/08/23 17:38:58 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

/*

@def
	`ft_strlen.c : ft_strlen`

@brief
	Counts the number of characters in a string (The length of the string).

@man
	The strlen() function calculates the length of the string
	pointed to by s, excluding the terminating null byte ('\0').

@synopsis
	`size_t	ft_strlen(const char *s)`

@params
	`const char *s` The string buffer to count.

@return
	`size_t` the number of bytes in the string pointed to by `s`.

@notes
	Throw everything out the window, hyper optimize it,
	pray and finally find out its not faster than glibc

*/

size_t	ft_strlen(const char *s)
{
	const size_t __attribute__	((__may_alias__))	*w;
	const char										*s0 = s;

	if (!s)
		return (0);
	while ((uintptr_t)s % sizeof(size_t))
		if (!*s++)
			return (s - s0 - 1);
	w = (const void *)s;
	while (!((*w) - ((size_t)-1 / UCHAR_MAX) & ~(*w)
			& (((size_t)-1 / UCHAR_MAX)
				* (UCHAR_MAX / 2 + 1))))
		++w;
	s = (const void *)w;
	while (*s++)
		;
	return (s - s0);
}
