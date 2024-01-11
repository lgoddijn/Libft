/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:56:18 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/01/11 15:37:01 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

/*

@def
	`ft_isprint.c : ft_isprint`

@brief
	Checks if a character is printable.

@man
	Checks for any printable character including space.

@synopsis
	`int	ft_isprint(int c);`

@params
	`int c` an integer which must represent an unsigned character or EOF.

@returns
	`int` 0 if `c` is not printable or is not an unsigned char.
	`int` 1 if `c` is a printable character.

@notes
	`c` is required to be an unsigned char OR `EOF`
	therefore the function has to check if c is less than 0 and not `-1`.
	An unsigned char is essentially an unsigned integer.

	Note that the inclusive ascii code range is (32, 126)

*/

int	ft_isprint(int c)
{
	if (c < 0 && c != EOF)
		return (c);
	return (c >= ' '
		&& c <= '~');
}
