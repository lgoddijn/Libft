/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:28:58 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/11/22 17:26:14 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*

@def
	`ft_strmapi.c : ft_strmapi`

@brief
	Applies the function ’f’ to each character of the string ’s’.

@description
	Applies the function ’f’ to each character of the
	string ’s’, and passing its index as first argument
	to create a new string (with ft_calloc) resulting
	from successive applications of ’f’.

@synopsis
	`char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));`

@params
	`char const *s` The string buffer to which `f` should be applied.
	`char (*f)(unsigned int, char)` The function to apply to each char in `s`.

@return
	`char *` The pointer to the first char in the new string.
	`NULL` If the allocation for the new string buffer fails.

@see
	`ft_strlen.c : ft_strlen`
	`ft_calloc.c : ft_calloc`

@extern
	`stdlib.h : malloc(3)`

@notes
	When allocating the function has to `+ 1` for the null-terminator.
	When calling the `f` function i has to be cast to an `unsigned int`
	since `f` takes an `unsigned int` as the first argument.

	The function should also account for invalid arguments.

	We do not need to call `ft_bzero` before the loop
	since `ft_calloc` already sets all bytes to `0`.

	The alloc increment cannot be done in the set statement.

*/

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	const size_t	s_len = ft_strlen(s);
	char			*start;
	char			*alloc;

	if (!s || !f)
		return (NULL);
	alloc = (char *)ft_calloc
		(s_len + 1, sizeof(char));
	if (!alloc)
		return (NULL);
	start = alloc;
	while (*s)
	{
		*alloc = f((unsigned int) \
		(alloc - start), *s++);
		++alloc;
	}
	return (start);
}
