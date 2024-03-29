/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:48:43 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/02/02 16:02:15 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

/*

@def
	`ft_strnstr.c : ft_strnstr`

@brief
	Finds the first occurrence of a substring.

@man
    The strnstr() function locates the first occurrence of the null-termi‐
    nated string little in the string big, where not more than len characters
    are searched.  Characters that appear after a ‘\0’ character are not
    searched.  Since the strnstr() function is a FreeBSD specific API, it
    should only be used when portability is not a concern.

@synopsis
	`char	*ft_strnstr(const char *big, const char *little, size_t len);`

@params
	`const char *big` The string to search for `little`.
	`const char *little` The substring to find in `big`.
	`size_t len` The maximum number of characters to go through.

@return
	`char *` The pointer to the first char in `big` which matches `little`.
	`NULL` If no instance of `little` is found in `big`.

@notes
	If `little` is invalid then the original function returns `big`.
	In our case we return `NULL` since the original one makes no sense.

	The function goes through `big` at the first
	occurrence of the first character of `little`
	The `static check_substring` function is called.
	This function attempts to check the entire character sequence.

*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const size_t	little_len = ft_strlen(little);
	size_t			i;

	i = SIZE_MAX;
	if (!big || !little || !*little)
		return (NULL);
	while (++i < len && big[i])
		if (big[i] == *little && i + little_len <= len)
			if (ft_strncmp(big + i, little, little_len) == 0)
				return ((char *)(big + i));
	return (NULL);
}
