/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:55:17 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/22 16:25:37 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

	The "is" functions have a tendency to return numbers such as `1024` and `2048`
	if the condition is met. However the original design of these functions is to
	return `0` and `1`, therefore these functions do not account for those returns.

*/

int	ft_isdigit(int c)
{
	if (c < 0 && c != EOF)
		return (c);
	return (c >= '0'
		&& c <= '9');
}
