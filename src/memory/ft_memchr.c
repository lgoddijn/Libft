/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:51:52 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/14 18:22:24 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_memory.h"

/*

@def
	`ft_memchr.c : ft_memchr`

@brief
	Scans memory for a character.

@man
	The memchr() function scans the initial n bytes of the
	memory area pointed to by s for the first instance of c. 
	Both c and the bytes of the memory area
	pointed to by s are interpreted as unsigned char.

@synopsis
	`void	*ft_memchr(const void *s, int c, size_t n)`

@params
	`const void *s`	The source buffer which should be scanned.
	`int c` 		The value that should be looked for in `s`.
	`size_t n`		The number of bytes that should be checked.

@return
	`void *` A pointer to the first character in `s`
			 that matches `c` or NULL if nothing is found.

@notes
	Because the void ptr buffer is of type `T` we simply
	cast the pointer to an `unsigned char` aka. `int`
	this allows the function to go through the memory without type issues.

	However the function should cast the return back to `void *`.

	The initial argument check at the start also checks for `n`
	Even though the loop would not execute if `n` was `0`
	This is a slight efficiency buff since the check
	is executed regardless. Secondly, I updated it 
	to not use indexes since pointer arithmetic is faster.

*/

void	*ft_memchr(const void *s, int32_t c, size_t n)
{
	unsigned char		*ptr;
	unsigned char		target;

	if (!s || !n)
		return (NULL);
	ptr = (unsigned char *)s;
	target = (unsigned char)c;
	while (n--)
		if (*ptr++ == target)
			return ((void *)--ptr);
	return (NULL);
}
