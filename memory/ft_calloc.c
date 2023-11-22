/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:56:40 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/11/22 16:36:18 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*

@def
	`ft_calloc.c : ft_calloc`

@brief
	Allocates `nmemb` elements of size `size`.

@man
    The calloc() function allocates memory for an array of  nmemb  elements
    of  size bytes each and returns a pointer to the allocated memory.  The
    memory is set to zero.  If nmemb or size is 0,  then  calloc()  returns
    either  NULL,  or a unique pointer value that can later be successfully
    passed to free().  If the multiplication of nmemb and size would result
    in  integer  overflow, then calloc() returns an error.  By contrast, an
    integer overflow would not be detected in the following  call  to  mal‐
    loc(),  with the result that an incorrectly sized block of memory would
    be allocated:

        malloc(nmemb * size);

@synopsis
	`void	*ft_calloc(size_t nmemb, size_t size);`

@params
	`size_t nmemb` The number of elements.
	`size_t n`	   The byte-size of each element.

@returns
	`void *` A pointer to the first address allocated.

@see
	`stdlib.h : malloc(3)`
	`ft_bzero.c : ft_bzero`

@extern
	`stdlib.h : malloc(3)`

@notes
	There are a few ways to go about calloc.
	Some implementations return `NULL` when
	either argument is `0`. Others, instead
	allocate using malloc an area of `0`.

	When passing `0` to malloc, some implementations
	will return `NULL`, however most commonly
	the function will return a unique memory area
	which cannot be dereferenced. However it is
	applicable in `free(3)`.

	Because of that if you were to use it in production
	it would be dangerous giving a segfault trying to
	dereference a pointer that cannot be dereferenced.

	Therefore the best implementation is to set
	both arguments to `1` when either is `0`
	resulting in a memory area of `1`.
	This area is basically equivalent to an empty
	string and many other buffer types. Giving a
	more useful return and less risk of crashing.

	Most modern implementations of calloc do this.
	The GNU calloc does this as well, since we
	are using ubuntu that is the function these
	machines use and I chose to replicate.

	Further, the function would crash in the
	overflow check if the values were left as `0`
	Since division by `0` will give an error.

	While the original function does not check
	for overflow, it is best to check for allocation
	overflow by checking if `nmemb` * `size` is overflowing.
	
	`ft_bzero` is called to set all memory to 0 (the default).

	The function doesn't need to check the allocation
	Since `ft_bzero` already checks it and the following
	statement is the return anyways.

*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc;

	if (SIZE_MAX / nmemb < size)
		return (NULL);
	alloc = malloc(nmemb * size);
	ft_bzero(alloc, nmemb * size);
	return (alloc);
}
