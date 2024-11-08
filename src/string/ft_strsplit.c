/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:37:37 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/08 20:00:10 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

static char	**alloc_fail(
	char **__restrict__ __tokens,
	const char *__restrict__ __copy
)
{
	ft_free2d((void **)__tokens);
	free((void *)__copy);
	return (NULL);
}

char	**ft_strsplit(
	const char *__restrict__ s,
	const char *__restrict__ set
)
{
	const char	*copy = ft_strdup(s);
	char		**tokens;
	char		*token;
	size_t		size;

	if (!s || !copy)
		return (NULL);
	size = 0;
	tokens = (char **)malloc(2 * sizeof(char *));
	if (!tokens)
		return (alloc_fail(tokens, copy));
	token = ft_strtok((char *)copy, set);
	while (token)
	{
		tokens[size++] = ft_strdup(token);
		if (!tokens[size - 1])
			return (alloc_fail(tokens, copy));
		tokens = ft_realloc(tokens, size
				* sizeof(char *), (size + 1) * sizeof(char *));
		if (!tokens)
			return (alloc_fail(tokens, copy));
		token = ft_strtok(NULL, set);
	}
	tokens[size] = NULL;
	return (free((void *)copy), tokens);
}
