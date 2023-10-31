/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:37:37 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/31 16:29:05 by lgoddijn         ###   ########.fr       */
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
	`stdlib.h : free(3)`

@extern
	`stdlib.h : malloc(3)`
	`stdlib.h : free(3)`

@notes
	The first thing this function does is check its arguments.
	Then the function works by getting the amount of words in the string.
	Where it then splits all the words and allocates the space for them.

	There's a lot of allocation stuff going on,
	so memory leaks are to be kept in mind.

	Each string should also be null terminated.
	Therefore when allocating `+ 1` should be specified.

	The `static split_words` function should handle memory leaks from
	`static next_word` therefore it will return `-1` on error.

	The final element of the 2D array should be `NULL`.

	When passing a string containing only the delimiter
	character, an array containing `NULL, NULL` should be returned.
	This is because while there are three possible approaches,
	this is the best as normally you would wanna do `while (*arr)`.

	The three possible approaches would be the following returns:

	`NULL, NULL` ; `"", NULL` ; `"" * strlen, NULL`. 

*/

static int	word_count(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*next_word(char const **s, char c, size_t *len)
{
	size_t	i;
	char	*word;

	*len = 0;
	while (**s == c)
		(*s)++;
	while ((*s)[*len] && (*s)[*len] != c)
		(*len)++;
	word = (char *)ft_calloc(*len + 1, sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < *len)
	{
		word[i] = (*s)[i];
		i++;
	}
	word[i] = '\0';
	*s += *len;
	return (word);
}

static int	split_words(char **split, int words, const char *s, char c)
{
	int		i;
	size_t	len;

	i = 0;
	while (i < words)
	{
		split[i] = next_word(&s, c, &len);
		if (!split[i])
		{
			while (i > 0)
				free(split[--i]);
			return (K0_C_LMA0);
		}
		i++;
	}
	split[i] = NULL;
	return (C_0K_LMA0);
}

char	**ft_split(char const *s, char c)
{
	int		word_c;
	char	**split;

	if (!s)
		return (NULL);
	word_c = word_count(s, c);
	split = (char **)ft_calloc(word_c + 1, sizeof(char *));
	if (!split)
		return (NULL);
	if (!split_words(split, word_c, s, c))
	{
		free(split);
		return (NULL);
	}
	return (split);
}
