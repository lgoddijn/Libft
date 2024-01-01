/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:59:40 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:11:37 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

/*

@def
	`ft_strnjoin.c : ft_strnjoin`

@brief
	Joins multiple strings together.

@description
	Allocates (with `ft_calloc`) and returns a new
	string, which is the merged parent of all the
	substrings within the 2d array `strings`.

@synopsis
	`char	*ft_strnjoin(char **strings, size_t n, bool should_free);`

@params
	`char **strings` The 2d array of strings to join.
	`size_t n` The number of strings within the array or that you wish to merge.
	`bool should_free` A switch to specify if the array should be freed.

@return
	`char *` The new merged string buffer.
	`NULL` If the allocation fails.

@see
	`ft_strlen.c : ft_strlen`
	`ft_calloc.c : ft_calloc`
	`ft_memcpy.c : ft_memcpy`

@extern
	`stdlib.h : malloc(3)`
	`stdlib.h : free(3)`

@notes
	The function just merges the strings (up to `n`)
	within the `strings` 2d array. The `should_free`
	argument presumes that both dimensions of the array
	are freeable. Also, the function will return `NULL`
	if the allocation fails, but it also will free
	the original input array. This will change eventually
	but right now I can't be bothered with norminette.

*/

char	*ft_strnjoin(char **strings, size_t n, bool should_free)
{
	const char	**strs = \
	(const char **)strings;
	char		*alloc;
	size_t		a_size;
	size_t		len;

	a_size = 0;
	if (!strings)
		return (NULL);
	while (*strings)
		a_size += ft_strlen(*strings++);
	strings = (char **)strs;
	alloc = (char *)ft_calloc(a_size + 1, sizeof(char));
	while (n--)
	{
		len = ft_strlen(*strings);
		ft_memcpy(alloc, *strings, len);
		alloc += len;
		if (should_free)
			free(*strings);
		++*strings;
	}
	if (should_free)
		free(strings);
	return (alloc);
}
