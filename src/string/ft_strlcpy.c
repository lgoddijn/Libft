/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:50:07 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/08 19:59:57 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

/*

@def
	`ft_strlcpy.c : ft_strlcpy

@brief
	Copies a string into a destination buffer (size bounded).

@man
    The strlcpy() and strlcat() functions copy and concatenate strings re‐
    spectively.  They are designed to be safer, more consistent, and less er‐
    ror prone replacements for strncpy(3) and strncat(3).  Unlike those func‐
    tions, strlcpy() and strlcat() take the full size of the buffer (not just
    the length) and guarantee to NUL-terminate the result (as long as size is
    larger than 0 or, in the case of strlcat(), as long as there is at least
    one byte free in dst).  Note that a byte for the NUL should be included
    in size.  Also note that strlcpy() and strlcat() only operate on true “C”
    strings.  This means that for strlcpy() src must be NUL-terminated and
    for strlcat() both src and dst must be NUL-terminated.

    The strlcpy() function copies up to size - 1 characters from the NUL-ter‐
    minated string src to dst, NUL-terminating the result.


@synopsis
	`size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);`

@params
	`char *dst` The string buffer to which `src` should be copied.
	`const char *src` The string to copy into `dst`.
	`size_t dstsize` The maximum size of bytes to copy.

@return
	`size_t` The attempted number of bytes copied.

@see
	`ft_strlen.c : ft_strlen`

@notes
	This function is designed to be memory safe.
	Therefore when using it you have to allocate
	enough space in the `dst` buffer for the `src` string.

	ex. char dst[size];

	The function returns the length of `src`.

*/

static __always_inline void	__prep_align_cpy(char *d, const char *s, size_t n)
{
	while ((uintptr_t)s & (sizeof(size_t) - 1) && n--)
	{
		*d = *s;
		++s;
		++d;
	}
}

static __always_inline void	__do_da_funky_loop(
		const t_word *ws, size_t *wd, size_t n)
{
	while (n >= sizeof(size_t)
		&& !(((*ws) - ((size_t) - 1 / UCHAR_MAX))
			& ~(*ws) & (((size_t)-1 / UCHAR_MAX)
				* (UCHAR_MAX / 2 + 1))) && ++ws && ++wd)
	{
		*(wd - 1) = *(ws - 1);
		n -= sizeof(size_t);
	}
}

static __always_inline void	__final_cpy(
		char *d, const char *s, size_t n)
{
	while (n--)
	{
		*d = *s;
		++s;
		++d;
	}
	*d = 0;
}

size_t	ft_strlcpy(char *d, const char *s, size_t n)
{
	const char		*d0 = d;
	const t_word	*ws;
	size_t			*wd;

	if (!n--)
		return (d - d0 + ft_strlen(s));
	if (((uintptr_t)s & (sizeof(size_t) - 1)) \
	== ((uintptr_t)d & (sizeof(size_t) - 1)))
	{
		__prep_align_cpy(d, s, n);
		if (n && *s)
		{
			wd = (void *)d;
			ws = (const void *)s;
			__do_da_funky_loop(ws, wd, n);
			d = (void *)wd;
			s = (const void *)ws;
		}
	}
	__final_cpy(d, s, n);
	return (d - d0 + ft_strlen(s));
}
