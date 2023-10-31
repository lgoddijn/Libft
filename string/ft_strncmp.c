/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:47:42 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/31 16:29:38 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*

@def
	`ft_strcmp.c : ft_strcmp`

@brief
	Compares two strings up to the `n`th character.

@man
	The  strcmp()  function compares the two strings s1 and s2.  The locale
	is not taken into account (for  a  locale-aware  comparison,  see  str‐
	coll(3)).  The comparison is done using unsigned characters.

@synopsis
	`int	ft_strncmp(const char *s1, const char *s2, size_t n)`

@params
	`const char *s1` The lefthand string buffer operand.
	`const char *s2` The righthand string buffer operand.
	`size_t n` The amount of bytes that should be compared for each string.

@returns
	`int` A number that is less than, equal to, or greater than zero
		  if s1 (or the first n bytes thereof) is found, respectively,
		  to be less than, to match, or be greater than s2.

@notes
	I know its hard to understand but bare with me...

	First the function checks if the arguments are valid.
	Then the function enters a loop which checks for how
	long the character in `s1` is equal to the next
	character in `s2`. Simultaneously the `n` condition
	is accounted for. If at any point the characters are
	still equal and `s1` terminates, then we know that
	the two strings are equal. Otherwise, once they are
	not equal we can backtrack `s2` to the previous
	character such that the position of both string is equal.
	We can then return the `unsigned char` difference of the two.

	The cast for `unsigned char` isn't too important, however
	it serves portability and memory applications when dealing
	with integer conversion on certain systems.

*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n || !s1 || !s2)
		return (0);
	while (*s1 == *s2++ && --n > 0)
		if (!*s1++)
			return (0);
	return (*(unsigned char *)s1 - \
			*(unsigned char *)--s2);
}
