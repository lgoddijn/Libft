/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:46:43 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/08 17:47:25 by lgoddijn         ###   ########.fr       */
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
	pray and finally find out its not faster than glibc.
	This is a stupid fucking function.

	Way I do it is to abuse cpu words where on 32 bit arch
	a word is 4 bytes and 64bit would be 8 bytes. Then by
	masking out bytes to the size of a word repeatedly I can
	quickly check word chunks of the string for 0s, aka the
	end of the string.

	Also this only works on a little endian byte order 64bit cpu
	cuz Im too lazy to norminette 5 billion preproc statements

*/

size_t	ft_strlen(const char *__restrict__ s)
{
	register const uintptr_t	s0 = (uintptr_t)s;
	register const t_word		*w = (const t_word *)(((uintptr_t)s) & \
									-((uintptr_t)(sizeof(t_word))));
	register const t_word		m = ((t_word)-1 / 0xff) * 0x7f;
	register t_bytemask			mask;
	register t_word				wi;

	if (!s || !*s)
		return (0);
	wi = *w;
	mask = ~(((wi & m) + m) | wi | m) >> (
			CHAR_BIT * (s0 % sizeof(t_word)));
	if (mask)
		return (__builtin_ctzl(mask) / CHAR_BIT);
	wi = *++w;
	while (!((wi - (((t_word)-1 / 0xff) * 0x01))
			& ~wi & (((t_word)-1 / 0xff) * 0x80)))
		wi = *++w;
	wi = (wi - ((t_word)-1 / 0xff) * 0x01) & ~wi & ((t_word)-1 / 0xff) * 0x80;
	wi = (__builtin_ctzl(wi) / CHAR_BIT);
	return (((const char *)w) + wi - s);
}
