/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:37:37 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:11:52 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

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

static size_t	get_substr_count(const char *s, char c)
{
	size_t	count;
	bool	in_word;

	count = 0;
	in_word = false;
	while (*s)
	{
		if (*s != c && !in_word && ++count)
			in_word = true;
		if (*s++ == c)
			in_word = false;
	}
	return (count);
}

static char	*get_next_substr(const char **s, char c)
{
	char	*substr;
	size_t	len;

	len = 0;
	while (**s == c)
		++*s;
	while ((*s)[len] && (*s)[len] != c)
		++len;
	substr = ft_substr(*s, 0, len);
	if (!substr)
		return (NULL);
	*s += len;
	return (substr);
}

char	**ft_strsplit(const char *s, char c, bool should_free)
{
	char	*to_free;
	char	**alloc;
	size_t	count;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	to_free = (char *)s;
	count = get_substr_count(s, c);
	alloc = (char **)ft_calloc(count + 1, sizeof(char *));
	while (i < count && alloc)
	{
		alloc[i] = get_next_substr(&s, c);
		if (!alloc[i++])
		{
			while (i > 0)
				free(alloc[--i]);
			free(alloc);
			return (NULL);
		}
	}
	if (should_free && alloc)
		free((void *)to_free);
	return (alloc);
}
