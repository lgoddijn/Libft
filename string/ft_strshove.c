/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strshove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:18:25 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/11/03 16:10:02 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*

@def
	`ft_strshove.c : ft_strshove`

@brief
	Duplicates a string or joins two strings together.

@description
	Allocates (`with ft_calloc`) and returns a new
	string, which is either a duplicated string from
	either `s1` or `s2`, or a joined string of the two.

@synopsis
	`char	*ft_strshove(const char *s1, const char *s2);`

@params
	`const char *s1` The lefthand string buffer to join or duplicate.
	`const char *s2` The righthand string buffer to join or duplicate.

@return
	`char *` The new joined or duplicated string buffer.
	`NULL` If the allocation fails.

@see
	`ft_strlen.c : ft_strlen`
	`ft_calloc.c : ft_calloc`
	`ft_memcpy.c : ft_memcpy`

@extern
	`stdlib.h : malloc(3)`

@notes
	I originally came up with this to
	save a function in get_next_line.
	This is literally just both
	`ft_strdup` and `ft_strjoin`
	combined. If any argument is `NULL`
	the function doesn't care and tries to
	merge whatever it finds, of course this
	means that if a string is `NULL` then
	a copy of the string that isn't is returned.

	Also there's no `if (!alloc)` statement
	because the other functions handle it.

	Expect `NULL` if the allocation fails.

	Also yes. This is the exact same code
	as `ft_strjoin`, the functions handle
	weird behavior well enough that no
	modifications are needed to begin with.

	The point of this function is to simply
	be more semantic.

*/

char	*ft_strshove(const char *s1, const char *s2)
{
	const size_t	s1_len = ft_strlen(s1);
	const size_t	s2_len = ft_strlen(s2);
	char			*alloc;

	alloc = (char *)ft_calloc(s1_len + s2_len + 1, sizeof(char));
	ft_memcpy(alloc, s1, s1_len);
	ft_memcpy(alloc + s1_len, s2, s2_len);
	return (alloc);
}
