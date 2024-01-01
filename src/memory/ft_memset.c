/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:51:26 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:07:20 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_memory.h"

/*

@def
	`ft_memset.c : ft_memset`

@brief
	Fills memory with a constant byte.

@man
	The memset() function fills the first n bytes of the
	memory area pointed to by s with the constant byte c.

@synopsis
	`void	*ft_memset(void *s, int c, size_t n)`

@params
	`void *s`	The destination buffer for `n` bytes of `c` to be copied into.
	`int c` 	The value that should be copied in `s`.
	`size_t n`	The number of bytes that should be filled.

@return
	`void *` A pointer to the first character in `s`.

@notes
	Because the void ptr buffer is of type `T` we simply
	cast the pointer to an `unsigned char` aka. `int`
	this allows the function to go through the memory without type issues.

	The function also uses pointer arithmetics instead of indexes.
	Since the function is the foundation of a lot of others,
	This small decision will affect a large efficiency factor.

	The function must always return `s` regardless of errors.

*/

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	val;

	if (!s)
		return (s);
	ptr = (unsigned char *)s;
	val = (unsigned char)c;
	while (n--)
		*ptr++ = val;
	return (s);
}
