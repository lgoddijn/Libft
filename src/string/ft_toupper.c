/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:53:16 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:12:21 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

/*

@def
	`ft_toupper.c : ft_toupper`

@brief
	Converts a character to uppercase.

@man
	If c is a lowercase letter, toupper()
	returns its uppercase equivalent,
    if an uppercase representation
	exists in the current locale.
	otherwise, it returns c

@synopsis
	`int	ft_toupper(int c);`

@params
	`int c` The character to convert.

@return
	`int` The upper-case counterpart of `c`.
	`c` If `c` is less than `0` (Invalid char).
	`c` If `c` is already uppercase.

@notes
	`c` is required to be an unsigned char OR `EOF`.
	therefore the function has to check if c is less than 0 and not `-1`.
	An unsigned char is essentially an unsigned integer.

*/

int	ft_toupper(int c)
{
	if (c < 0 && c != EOF)
		return (c);
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	return (c);
}
