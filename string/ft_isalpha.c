/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:55:08 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/31 16:28:48 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*

@def
	`ft_isalpha.c : ft_isalpha`

@brief
	Checks if a character is alphabetic.

@man
	Checks for an alphabetic character; in the standard "C" locale,
	it is equivalent to (isupper(c) ||  islower(c)).   In  some  lo‐
	cales, there may be additional characters for which isalpha() is
	true—letters which are neither uppercase nor lowercase.

@synopsis
	`int	ft_isalpha(int c);`

@params
	`int c` an integer which must represent an unsigned character or EOF.

@returns
	`int` 0 if the character is not alphabetical or is not an unsigned char.
	`int` 1 if it is an alphabetical character.

@notes
	`c` is required to be an unsigned char OR `EOF`
	therefore the function has to check if c is less than 0 and not `-1`.
	An unsigned char is essentially an unsigned integer.

	The "is" functions have a tendency to return numbers such as `1024` and `2048`
	if the condition is met. However the original design of these functions is to
	return `0` and `1`, therefore these functions do not account for those returns.

*/

int	ft_isalpha(int c)
{
	if (c < 0 && c != EOF)
		return (c);
	return ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'));
}
