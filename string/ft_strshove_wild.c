/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strshove_wild.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:27:38 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/11/03 16:16:38 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*

@def
	`ft_strshove_wild.c : ft_strshove_wild`

@brief
	Duplicates a single string or joins multiple strings together.

@description
	Allocates (with `ft_calloc`) and returns a new
	string, which is either a duplicated string from
	`s1`, or a joined string of all the other strings.

@synopsis
	`char	*ft_strshove_wild(const char *s1, ...);`

@params
	`const char *s1` The lefthand string buffer to join or duplicate.
	`...` aka. `Ellipsis` The standard for an arbitrary argument vector.

@return
	`char *` The new joined or duplicated string buffer.
	`NULL` If the allocation fails.

@see
	`ft_strlen.c : ft_strlen`
	`ft_calloc.c : ft_calloc`
	`ft_memcpy.c : ft_memcpy`

@extern
	`stdlib.h : malloc(3)`
	`stdarg.h : va_start(3)`
	`stdarg.h : va_arg(3)`
	`stdarg.h : va_end(3)`

@notes
	I originally came up with this to
	save a function in get_next_line.
	This is literally just both
	`ft_strdup` and `ft_strjoin`
	combined. Unlike the regular
	`ft_strshove` this function
	takes things a step further
	and uses an indefinite amount
	of strings to join. The `wild`
	in the name is because this could
	be severely unsafe. The function
	currently has no protection against
	really large strings or a really
	large amount of strings.

	The function is also very inefficient.
	It's purpose is kinda like a wildcard.
	IF you really need to save lines then
	go ahead and use it. Keep in mind
	it uses `va` functions which are external.

*/

static void	shove(char *alloc, va_list args, const char *next)
{
	size_t	len;

	next = va_arg(args, const char *);
	while (next != NULL)
	{
		len = ft_strlen(next);
		ft_memcpy(alloc, next, len);
		alloc += len;
		next = va_arg(args, const char *);
	}
}

char	*ft_strshove_wild(const char *s1, ...)
{
	const size_t	s1_len = ft_strlen(s1);
	va_list			args;
	char			*alloc;
	size_t			total_len;
	const char		*next;

	total_len = s1_len;
	va_start(args, s1);
	next = va_arg(args, const char *);
	while (next != NULL)
	{
		total_len += ft_strlen(next);
		next = va_arg(args, const char *);
	}
	va_end(args);
	alloc = (char *)ft_calloc(total_len + 1, sizeof(char));
	if (!alloc)
		return (NULL);
	ft_memcpy(alloc, s1, s1_len);
	va_start(args, s1);
	shove(alloc + s1_len, args, next);
	va_end(args);
	return (alloc);
}
