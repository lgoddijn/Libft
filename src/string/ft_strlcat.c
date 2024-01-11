/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:48:02 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/01/11 15:37:35 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

/*

@def
	`ft_strlcat.c : ft_strlcat`

@brief
	Concatenates two strings together (size bounded).

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

	The strlcat() function appends the NULL-terminated
	string src to the end of dst. It will append at most
	size - strlen(dst) - 1 bytes, NUL-terminating the result.

	strlcat() traverses size characters without finding a NUL,
	the length of the string is considered to be size and the destination
	string will not be NUL-terminated (since there was no space for
    the NUL). This keeps strlcat() from running off the end of a string. In
    practice this should not happen (as it means that either size is incorrect
	or that dst is not a proper “C” string). The check exists to prevent
	potential security problems in incorrect code.

@synopsis
	`size_t	ft_strlcat(char *dst, const char *src, size_t size);`

@params
	`char *dst` The string buffer to which `src` should be concatenated.
	`const char *src` The string to concatenate to `dst`.
	`size_t size` The maximum size of the concatenated string.

@return
	`size_t` The attempted number of bytes concatenated.

@see
	`ft_strlen.c : ft_strlen`

@notes
	This function is designed to be memory safe.
	Therefore when using it you have to allocate
	enough space in the buffer for both strings.

	ex. char str[size] = "hello world!";

	The function returns the length of `dst` plus that of `src`

	The function is designed to be graceful. In cases of `NULL` arguments
	or anything of the sort the function will still return the length
	of `src` which when `src` is `NULL` will be `0` since `NULL` doesn't
	have any set length. This is in-line with the manual definition,
	however the original function considers this undefined behavior.
	This is just my simple safety measure to ensure nothing crashes.

	`dst` will always be guaranteed a null-terminator at the end.

	The `NULL` check for `dst` is vital to ensure the function
	always returns the length of `src`.

*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const size_t	dst_len = ft_strlen(dst);
	const size_t	src_len = ft_strlen(src);
	size_t			to_copy;

	if (!dst)
		return (src_len);
	if (dst_len >= size)
		return (src_len + size);
	to_copy = size - dst_len - 1;
	if (to_copy > src_len)
		to_copy = src_len;
	ft_memcpy(dst + dst_len, src, to_copy);
	dst[dst_len + to_copy] = '\0';
	return (dst_len + src_len);
}
