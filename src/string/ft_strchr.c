/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:49:03 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/08 20:19:56 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

/*

@def
	`ft_strchr.c : ft_strchr`

@brief
	Scans a string buffer for a character.

@man
	The  strchr() function returns a pointer to the first
	occurrence of the character c in the string s.

@synopsis
	`char	*ft_strchr(const char *s, int c);`

@params
	`const char *s` The string buffer to scan.
	`int c` The character to find.

@return
	`char *` The pointer to the first occurrence of `c`.

@notes
	The function checks if the character is
	the null-terminator, because the loop condition
	won't account for the null-terminator as part of the string.

	The null-terminator check must occur after the loop.
	This is because the loop must first reach the end of the string.

	The `strchr` function takes an `int` by design to account of `EOF`
	However modern implementations cast `c` to an `unsigned char` instead.
	Since `EOF`'s literal is `-1` an `unsigned char` will cast it to 0 instead.
	However using an `unsigned char` is advantageous for portability with
	platforms and compilers as well as sign extension where if you cast a
	`signed char` with a negative value to an `int`, sign extension can occur.
	For instance, if `char c = 0x80` (which is `-128` in two's complement),
	casting it directly to an `int` without first converting to `unsigned char`
	can result in `0xFFFFFF80` on a system with 4-byte integers.
	This is clearly not what we want.

*/

char	*ft_strchr(const char *s, int c)
{
	register const char	*r = ft_strchrnul(s, c);

	if (*(unsigned char *)r == (unsigned char)c)
		return ((char *)r);
	return (0);
}
