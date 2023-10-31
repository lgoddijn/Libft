/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:02:45 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/31 16:29:20 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*

@def
	`ft_strjoin.c : ft_strjoin`

@brief
	Joins two string buffers together.

@description
	Allocates (with ft_calloc) and returns a new
	string, which is the result of the concatenation
	of ’s1’ and ’s2’.

@synopsis
	`char	*ft_strjoin(char const *s1, char const *s2);`

@params
	`const char *s1` The lefthand string buffer to join.
	`const char *s2` The righthand string buffer to join.

@return
	`char *` The new joined string buffer.
	`NULL` If the allocation fails.

@see
	`ft_strlen.c : ft_strlen`
	`ft_calloc.c : ft_calloc`
	`ft_memcpy.c : ft_memcpy`

@extern
	`stdlib.h : malloc(3)`

@notes
	Since ft_strlen doesn't take into account the null-terminator
	The function has to `+ 1` in the allocation to account for it.

	The second `ft_memcpy` call shifts the allocation pointer by the length
	Such that the second string is copied after the first,
	since there was space allocated for `\0`, it will be copied from `s2`

	This function cannot be streamlined due to a memory leak when
	offsetting `NULL`, even if `s1_len` is `0`.

	According to the C standard (C11), section 6.5.6, paragraph 8:
    	If both the pointer operand and the result point to elements
		of the same array object, or one past the last 
		element of the array object, the evaluation shall not 
		produce an overflow; otherwise, the behavior is undefined.

	Therefore while `ft_memcpy` will handle a failed allocation
	appropriately, the argument passed could result in undefined
	behavior in older compilers or architectures. Therefore
	in this case the allocation should be checked.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	const size_t	s1_len = ft_strlen(s1);
	const size_t	s2_len = ft_strlen(s2);
	char			*alloc;

	alloc = ft_calloc(s1_len + s2_len + 1, sizeof(char));
	ft_memcpy(alloc, s1, s1_len);
	ft_memcpy(alloc + s1_len, s2, s2_len);
	return (alloc);
}
