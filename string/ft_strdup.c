/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:56:53 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/31 16:29:12 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*

@def
	`ft_strdup.c : ft_strdup`

@brief
	Duplicates a string buffer.

@man
    The  strdup() function returns a pointer to a new string which is a du‐
    plicate of the string s.  Memory for the new string  is  obtained  with
    malloc(3), and can be freed with free(3).

@synopsis
	`char	*ft_strdup(const char *s);`

@params
	`const char *s` The string buffer to clone.

@return
	`char *` The new duplicated string buffer.
	`NULL` If the allocation fails.

@see
	`ft_strlen.c : ft_strlen`
	`ft_calloc.c : ft_calloc`

@extern
	`stdlib.h : malloc(3)`

@notes
	Since ft_strlen doesn't take into account the null-terminator
	The function has to `+ 1` in the allocation to account for it.

	`ft_calloc` already sets everything to `0`.
	Therefore theres no need to null terminate
	after calling `ft_memcpy`.

	The function is very streamlined.
	The `ft_memcpy` function will return `dest`
	(which in this case is the allocation)
	if any argument, including `dest` is `NULL`
	Therefore no memory leaks will occur.

	The function also doesnt use `ft_strlcpy`
	regardless of semantics. This is because
	normally `ft_strlcpy` is used for raw
	string copying, safety and ensuring
	the null terminator. However in this case
	since calloc already ensures the null
	terminator and memcpy is already
	designed to be size-safe, for the
	sake of efficiency the function uses
	`ft_memcpy` instead of `ft_strlcpy`.

*/

char	*ft_strdup(const char *s)
{
	const size_t	s_len = ft_strlen(s);

	return (ft_memcpy((char *)ft_calloc(
				s_len + 1, sizeof(char)), s, s_len));
}
