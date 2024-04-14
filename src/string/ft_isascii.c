/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:55:59 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/14 18:29:12 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

/*

@def
	`ft_isascii.c : ft_isascii`

@brief
	Checks if a character is ascii.

@man
	Checks whether c is a 7-bit unsigned char
	value that fits into the ASCII character set.

@synopsis
	`int	ft_isascii(int c);`

@params
	`int c` an integer which must represent an unsigned character or EOF.

@returns
	`int` 0 if `c` is not ascii or is not an unsigned char.
	`int` 1 if `c` is an ascii character.

@notes
	`c` is required to be an unsigned char OR `EOF`
	therefore the function has to check if c is less than 0 and not `-1`.
	An unsigned char is essentially an unsigned integer.

*/

int32_t	ft_isascii(int32_t c)
{
	if (c < 0 && c != EOF)
		return (c);
	return ((c >= 0)
		&& (c <= 127));
}
