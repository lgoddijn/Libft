/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:53:55 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/14 18:33:48 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

/*

@def
	`ft_tolower.c : ft_tolower`

@brief
	Converts a character to lowercase.

@man
	If c is an uppercase letter, tolower()
	returns its lowercase equivalent,
	if a lowercase representation exists
	in the current locale.
	otherwise, it returns c.

@synopsis
	`int	ft_tolower(int c);`

@params
	`int c` The character to convert.

@return
	`int` The lower-case counterpart of `c`.
	`c` If `c` is less than `0` (Invalid char).
	`c` If `c` is already lowercase.

@notes
	`c` is required to be an unsigned char OR `EOF`.
	therefore the function has to check if c is less than 0 and not `-1`.
	An unsigned char is essentially an unsigned integer.

*/

int32_t	ft_tolower(int32_t c)
{
	if (c < 0 && c != EOF)
		return (c);
	if (c >= 'A' && c <= 'Z')
		return (c - ('A' - 'a'));
	return (c);
}
