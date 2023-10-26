/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:46:43 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/23 17:00:38 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

@def
	`ft_strlen.c : ft_strlen`

@brief
	Counts the number of characters in a string (The length of the string).

@man
	The strlen() function calculates the length of the string
	pointed to by s, excluding the terminating null byte ('\0').

@synopsis
	`size_t	ft_strlen(const char *s)`

@params
	`const char *s` The string buffer to count.

@return
	`size_t` the number of bytes in the string pointed to by `s`.

@notes
	This function does not account for the null-terminator
	when counting the length of the string.

	ex. "hello\0" -> size_t 5

	Note that the `if (!s)` statement is vital
	for a lot of other functions in this library.

*/

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (len);
	while (s[len])
		++len;
	return (len);
}
