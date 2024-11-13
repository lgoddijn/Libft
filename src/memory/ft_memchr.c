/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:51:52 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/11 20:56:45 by lgoddijn         ###   ########.fr       */
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

static __always_inline void	__do_loop(
		size_t *n, const t_word *w, size_t k)
{
	while (*n >= sizeof(size_t)
		&& !(((*w ^ k) - ((size_t) - 1 / UCHAR_MAX))
			& ~(*w ^ k) & (((size_t) - 1 / UCHAR_MAX)
				* (UCHAR_MAX / 2 + 1))) && ++w)
		*n -= sizeof(size_t);
}

void	*ft_memchr(const void *src, int c, size_t n)
{
	register const unsigned char	*s = src;
	register const t_word			*w;
	register size_t					k;

	if (!src || !n)
		return (NULL);
	c = (unsigned char)c;
	while ((uintptr_t)s & (sizeof(size_t) - 1) && n && *s != c)
	{
		++s;
		--n;
	}
	if (n && *s != c)
	{
		k = ((size_t) - 1 / UCHAR_MAX) * c;
		w = (const void *)s;
		__do_loop(&n, w, k);
		s = (const void *)w;
	}
	while (n && *s != c && --n)
		++s;
	if (n)
		return ((void *)s);
	return (0);
}
