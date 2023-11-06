/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:14:57 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/11/06 14:38:20 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*

@def
	`ft_strtrim.c : ft_strtrim`

@brief
	Removes characters in `set` from `s1`.

@description
	Allocates (with ft_calloc) and returns a copy of
	’s1’ with the characters specified in ’set’ removed
	from the beginning and the end of the string.

@synopsis
	`char	*ft_strtrim(char const *s1, char const *set);`

@params
	`char const *s1` The string to clean.
	`char const *set` The set of characters that should be removed from `s1`.

@return
	`char *` The new cleaned string buffer.
	`NULL` If the allocation for the new string fails.

@see
	`ft_strchr.c : ft_strchr`
	`ft_strlen.c : ft_strlen`
	`ft_calloc.c : ft_calloc`

@extern
	`stdlib.h : malloc(3)`

@notes
	This function goes through `s1`
	where any character which is in `set`
	will be removed, the description
	on the subject is slightly misleading.

*/

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*alloc;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		++start;
	end = ft_strlen(s1);
	while (end > start && ft_strrchr(set, s1[end - 1]))
		--end;
	alloc = (char *)ft_calloc(end - start + 1, sizeof(char));
	if (!alloc)
		return (NULL);
	ft_memcpy(alloc, s1 + start, end - start);
	return (alloc);
}
