/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:23:49 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/17 00:46:48 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_heap.h"

/*

@def
	`ft_realloc.c : ft_realloc`

@brief
	Reallocates memory on the heap.

@man
	The realloc() function changes the size of the memory block pointed  to
	by ptr to size bytes.  The contents will be unchanged in the range from
	the start of the region up to the minimum of the old and new sizes.  If
	the  new size is larger than the old size, the added memory will not be
	initialized.  If ptr is NULL, then  the  call  is  equivalent  to  mal‐
	loc(size), for all values of size; if size is equal to zero, and ptr is
	not NULL, then the call is equivalent  to  free(ptr).   Unless  ptr  is
	NULL,  it  must have been returned by an earlier call to malloc(), cal‐
	loc(), or realloc().  If the area pointed to was moved, a free(ptr)  is
	done.

@synopsis
	`void	*ft_realloc(void *ptr, size_t size);`

@params
	`void *ptr` The source pointer to reallocate.
	`size_t size` The size of memory to allocate.

@return
	`void *` The `alloc` pointer (regardless of failure).

@see
	`ft_memcpy.c : ft_memcpy`

@extern
	`stdlib.h : malloc(3)`
	`stdlib.h : free(3)`

@notes
	First we malloc the new memory area, before then
	copying all the bytes over. Note that memcpy will
	not fail with `NULL` arguments. Since the function
	returns `malloc(0)` if size is `0` we add it to the
	condition, where we only free `ptr` if the allocation
	was successfully and `ptr` is a valid pointer.

*/

void	*ft_realloc(void *ptr, size_t size)
{
	void	*alloc;

	alloc = malloc(size);
	ft_memcpy(alloc, ptr, size);
	if (alloc && ptr)
		free((void *)ptr);
	return (alloc);
}
