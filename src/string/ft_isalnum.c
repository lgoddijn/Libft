/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:55:38 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/01/11 15:36:33 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

/*

@def
	`ft_isalnum.c : ft_isalnum`

@brief
	Checks if a character is alphanumeric.

@man
	Checks for an alphanumeric character;
	it is equivalent to (isalpha(c) || isdigit(c)).

@synopsis
	`int	ft_isalnum(int c);`

@params
	`int c` an integer which must represent an unsigned character or EOF.

@returns
	`int` 0 if the character is not alphanumerical or is not an unsigned char.
	`int` 1 if it is an alphanumerical character.

@notes
	`c` is required to be an unsigned char OR `EOF`
	therefore the function has to check if c is less than 0 and not `-1`.
	An unsigned char is essentially an unsigned integer.

*/

int	ft_isalnum(int c)
{
	if (c < 0 && c != EOF)
		return (c);
	return (ft_isalpha(c)
		|| ft_isdigit(c));
}
