/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:46:53 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/14 18:33:36 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

/*

@def
	`ft_substr.c : ft_substr`

@brief
	Creates a new substring instance from the parent string.

@description
	Allocates (with ft_calloc) and returns a substring from the string ’s’.
	The substring begins at index ’start’ and is of maximum size ’len’.

@synopsis
	`char	*ft_substr(char const *s, unsigned int start, size_t len);`

@params
	`char const *s` The parent string buffer.
	`unsigned int start` The substring starting index (from parent `s`).
	`size_t len` The length of the substring.

@return
	`char *` The new substring instance.
	`NULL` If the allocation fails.

@see
	`ft_strlen.c : ft_strlen`
	`ft_strdup.c : ft_strdup`
	`ft_calloc.c : ft_calloc`
	`ft_memcpy.c : ft_memcpy`

@extern
	`stdlib.h : malloc(3)`

@notes
	The allocation is `+ 1` to include the null-terminator.
	We should account for invalid range by returing an empty string.
	The mempy function is called at the `s` pointer plus the start.

	No need to null-terminate the string since
	calloc already sets everything to `0` aka `\0`

	The function does not need to check if the allocation failed.
	`ft_memcpy` will not crash if `NULL` is passed and such the
	function will still return `NULL` if the allocation fails.

	Note that the use of `ft_strdup` is important because
	the return of this function must be freeable at all times.

	The function does not need to account for the null-terminator
	since calloc already sets everything to `0` and `ft_memcpy`
	will not override the last byte in the buffer.

*/

char	*ft_substr(char const *s, uint32_t start, size_t len)
{
	const size_t	s_len = ft_strlen(s);
	char			*alloc;

	if (!s)
		return (NULL);
	if (start >= s_len || len == 0)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	alloc = (char *)ft_calloc(len + 1, sizeof(char));
	ft_memcpy(alloc, s + start, len);
	return (alloc);
}
