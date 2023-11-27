/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:37:37 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/11/22 17:24:16 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*

@def
	`ft_split.c : ft_split`

@brief
	Splits a string buffer into an array of sub-strings.

@description
	Allocates (with ft_calloc) and returns an array
	of strings obtained by splitting ’s’ using the
	character ’c’ as a delimiter. The array must end
	with a NULL pointer.

@synopsis
	`char	**ft_split(char const *s, char c);`

@params
	`char const *s` The string buffer to split.
	`char c` The delimiter character.

@return
	`char **` The 2D array containing each substring.
	`NULL` If the any nd allocation fails.

@see
	`ft_calloc.c : ft_calloc`
	`ft_realloc.c : ft_realloc`
	`ft_substr.c : ft_substr`
	`ft_strlen.c : ft_strlen`

@extern
	`stdlib.h : malloc(3)`
	`stdlib.h : free(3)`

@notes
	Ok the original version of this was terrible,
	I boiled it down to two functions. First the
	argument `s` is checked, then we can count the
	substrings within the 

	The final element of the 2D array should be `NULL`.

	When passing a string containing only the delimiter
	character, an array containing `NULL, NULL` should be returned.
	This is because while there are three possible approaches,
	this is the best as normally you would wanna do `while (*arr)`.

	The three possible approaches would be the following returns:

	`NULL, NULL` ; `"", NULL` ; `"" * strlen, NULL`. 

*/

static char	*get_next_substr(const char **s, char c, bool should_free)
{
	void	*to_free;
	char	*substr;
	size_t	len;

	len = 0;
	while (*(*s++) == c)
		;
	while ((*s)[len] && (*s)[len++] != c)
		;
	substr = ft_substr(*s, 0, len + 1);
	if (!substr)
		return (NULL);
	if (should_free)
	{
		to_free = (void *)s;
		s = ft_realloc((void *)*s + len,
				ft_strlen(*s + len));
		free(to_free);
	}
	else
		*s += len;
	return (substr);
}

char	**ft_strsplit(const char *s, char c, bool should_free)
{
	char	**alloc;
	size_t	count;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	count = 0;
	while (*s)
		if (*s++ != c)
			++count;
	alloc = (char **)ft_calloc(
			count + 1, sizeof(char *));
	while (i < count && alloc)
	{
		alloc[i] = get_next_substr(&s, c, should_free);
		if (!alloc[i++])
		{
			while (i > 0)
				free(alloc[--i]);
			free(alloc);
			return (NULL);
		}
	}
	return (alloc);
}