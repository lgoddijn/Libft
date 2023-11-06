/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:47:42 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/11/06 18:16:02 by lgoddijn         ###   ########.fr       */
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

@see
	`ft_strlen.c : ft_strlen`

@notes
	I know its hard to understand but bare with me...

	First the function checks if the arguments are valid.
	Since `n` is `size_t`, it is unsigned. Therefore we 
	must check that `n` is not `0` otherwise the loop will
	underflow to `SIZE_MAX`. If instead `s1` is not `NULL`
	while `s2` is, we return the string length of `s1` as
	`len(s1) - 0 = len(s1)`, respectively, if `s1` is `NULL`
	while `s2` isn't, then the difference is equivalent to
	`0 - len(s2) = -len(s2)`. The main loop of the function
	is designed to iterate through both strings as long as
	they are the same. We check that the values of `s1` and `s2`
	are the same before incrementing `s2`. We do not increment `s1`
	due to the check later on. We also simultaneously check that
	`n` is still above `0`. We do `--n` such that we decrement
	`n` before comparing since normally this is treated as an
	index and would therefore be accounted for `1` position behind.
	We then check that `s1` at the position we compared is still
	not the end of the string. if it isn't then we can increment
	`s1` and continue, otherwise because the two strings are the
	same, `s2` will also be terminated, therefore we know they are
	the same, so we can return `0`. Once we exit the loop we know
	that there is a difference in the strings. To ensure proper
	arithmetics we castt both strings to unsigned character buffers.
	Where we can then decrement `s2` once, since the original function
	has this odd behavior (ex. diff "test", "tests" == -1)
	(ex. diff "tests", "test" == 1). Notice how the position of the
	argument will change the sign of the output. This is also why
	at the start we return `-ft_strlen(s2)`. So we decrement `s2`
	before evaluating the difference and returning it.
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if ((!s1 && !s2) || !n)
		return (0);
	if (s1 && !s2)
		return (ft_strlen(s1));
	if (!s1 && s2)
		return (-ft_strlen(s2));
	while (*s1 == *s2++ && --n > 0)
		if (!*s1++)
			return (0);
	return (*(unsigned char *)s1 - \
			*(unsigned char *)--s2);
}
