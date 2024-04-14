/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:49:56 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/14 18:33:03 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

/*

@def
	`ft_strrchr.c : ft_strrchr

@brief
	Scans a string buffer for the last occurrence of a character.

@man
    The strrchr() function returns a pointer to the
	last occurrence of the character c in the string s.

@synopsis
	`char	*ft_strrchr(const char *s, int c);`

@params
	`const char *s` The string to scan for `c`.
	`int c` The character to find in `s`.

@return
	`char *` The pointer to the last occurrence of `c` in `s`.
	`NULL` If no instance of `c` is found in `s`.

@notes
	The function goes to the end of the string
	using its length and shifting the pointer,
	Such that then the function only needs to go
	backwards throughout the string.

	The `strrchr` function takes an `int` by design to account of `EOF`
	However modern implementations cast `c` to an `unsigned char` instead.
	Since `EOF`'s literal is `-1` an `unsigned char` will cast it to 0 instead.
	However using an `unsigned char` is advantageous for portability with
	platforms and compilers as well as sign extension where if you cast a
	`signed char` with a negative value to an `int`, sign extension can occur.
	For instance, if `char c = 0x80` (which is `-128` in two's complement),
	casting it directly to an `int` without first converting to `unsigned char`
	can result in `0xFFFFFF80` on a system with 4-byte integers.
	This is clearly not what we want.

	The returns must be cast.

*/

char	*ft_strrchr(const char *s, int32_t c)
{
	unsigned char	*ptr;
	unsigned char	target;
	unsigned char	*cmp_s;

	if (!s)
		return (NULL);
	cmp_s = (unsigned char *)s;
	ptr = cmp_s + ft_strlen(s);
	target = (unsigned char)c;
	if (target == '\0')
		return ((char *)ptr);
	while (ptr >= cmp_s)
		if (*ptr-- == target)
			return ((char *)++ptr);
	return (NULL);
}
