/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:52:45 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/31 16:28:18 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*

@def
	`ft_memmove.c : ft_memmove`

@brief
	Copy a memory area.

@man
	The memmove() function copies n bytes from memory area src to memory area dest.
	The memory areas may overlap: copying takes place as though the bytes in src
	are first copied into a temporary array that does not overlap src or dest,
	and the bytes are then copied from the temporary array to dest.

@synopsis
	`void	*ft_memmove(void *dest, const void *src, size_t n)`

@params
	`void *dest`		The destination buffer for the `src` bytes.
	`const void *src`	The source buffer that should be copied.
	`size_t n`			The number of bytes that should be copied.

@return
	`void *` The pointer to the first `dest` cell.

@notes
	Because the void ptr buffer is of type `T` we simply
	cast the pointer to an `unsigned char` aka. `int`
	this allows the function to go through the memory without type issues.

	Since this function just returns a pointer to dest,
	we dont need to cast it back to `void *`.

	By design this function should handle memory overlap from both sides.

	The `memmove` has undefined behavior when either buffer is `NULL`.
	So it is designed to crash or return `dest` at all times.
	However since I improved upon the function. It is vital that
	the function does not return `NULL` when either buffer is `NULL`.
	Instead it should always return `dest` even when handling errors.

	The function also uses pointer arithmetics instead of indexes.
	Since the function is the foundation of a lot of others,
	This small decision will affect a large efficiency factor.

*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr1;
	const unsigned char	*ptr2 = \
	(const unsigned char *)src;

	ptr1 = (unsigned char *)dest;
	if (dest == src || n == 0
		|| !dest || !src)
		return (dest);
	if (ptr1 > ptr2)
	{
		ptr1 += n;
		ptr2 += n;
		while (n--)
			*(--ptr1) = *(--ptr2);
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
