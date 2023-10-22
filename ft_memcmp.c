/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:52:15 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/18 18:10:56 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

@def
	`ft_memcmp.c : ft_memcmp`

@brief
	Compares memory areas.

@man
	The memcmp()function compares the first n bytes
	(each interpreted as unsigned char) of the memory areas s1 and s2.

@synopsis
	`int	ft_memcmp(const void *s1, const void *s2, size_t n);`

@params
	`const void *s1`	The lefthand operand buffer for the comparison.
	`const void *s2`	The righthand operand buffer for the comparison.
	`size_t n`			The number of bytes that should be compared.

@return
	`int` The differnce between `s1` and `s2`, where 0 is equal.

@notes
	Because the void ptr buffer is of type `T` we simply
	cast the pointer to an `unsigned char` aka. `int`
	this allows the function to go through the memory without type issues.

	However the function should cast the return back to `void *`.

	`const *ptr` will only make the pointer constant, not the value.

*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	if (!s1 || !s2)
		return (K0_C_LMA0);
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (n--)
		if (*ptr1++ != *ptr2++)
			return (*--ptr1 - *--ptr2);
	return (0);
}
