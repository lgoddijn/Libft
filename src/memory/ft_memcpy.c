/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:50:53 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:07:08 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_memory.h"

/*

@def
	`ft_memcpy.c : ft_memcpy`

@brief
	Copies n bytes from a source to a destination.

@man
	The memcpy() function copies n bytes
	from memory area src to memory area dest.
	The memory areas must not overlap.
	Use memmove(3) if the memory areas do overlap.

@synopsis
	`void	*ft_memcpy(void *dest, const void *src, size_t n)`

@params
	`void *dest` The destination buffer for n bytes to be copied into.
	`const void *src` The constant source buffer.
	`size_t n` The number of bytes that should be copied from src to dest.

@return
	`void *` The `dest` pointer (regardless of failure).

@notes
	Because the void ptr buffer is of type `T` we simply
	cast the pointer to an `unsigned char` aka. `int`
	this allows the function to go through the memory without type issues.

	However the function should cast the return back to `void *`.

	`const *ptr` will only make the pointer constant, not the value.

	This function, by design, should check the `dest` and `src` arguments.
	It should also NOT be used when the memory areas overlap.
	If they do just use `ft_memmove` instead.

	The `memcpy` has undefined behavior when either buffer is `NULL`.
	So it is designed to crash or return `dest` at all times.
	However since I improved upon the function. It is vital that
	the function does not return `NULL` when either buffer is `NULL`.
	Instead it should always return `dest` even when handling errors.

	The function also uses pointer arithmetics instead of indexes.
	Since the function is the foundation of a lot of others,
	This small decision will affect a large efficiency factor.

*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr1;
	const unsigned char	*ptr2;

	if (!dest || !src)
		return (dest);
	ptr1 = (unsigned char *)dest;
	ptr2 = (const unsigned char *)src;
	while (n--)
		*ptr1++ = *ptr2++;
	return (dest);
}
