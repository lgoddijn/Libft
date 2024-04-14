/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:55:17 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/14 18:29:19 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

/*

@def
	`ft_isdigit.c : ft_isdigit`

@brief
	Checks if a character is a digit.

@man
	Checks for a digit (0 through 9).

@synopsis
	`int	ft_isdigit(int c);`

@params
	`int c` an integer which must represent an unsigned character or EOF.

@returns
	`int` 0 if `c` is not a digit or is not an unsigned char.
	`int` 1 if `c` is a digit character.

@notes
	`c` is required to be an unsigned char OR `EOF`
	therefore the function has to check if c is less than 0 and not `-1`.
	An unsigned char is essentially an unsigned integer.

*/

int32_t	ft_isdigit(int32_t c)
{
	if (c < 0 && c != EOF)
		return (c);
	return (c >= '0'
		&& c <= '9');
}
