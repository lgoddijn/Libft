/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:50:22 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/31 16:28:40 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*

@def
	`ft_atoi.c : ft_atoi`

@brief
	Converts a string buffer to an integer.

@man
    The  atoi() function converts the initial portion of the string pointed
    to by nptr to int.  The behavior is the same as

        strtol(nptr, NULL, 10);

    Except that atoi() does not detect errors.

@synopsis
	`int	ft_atoi(const char *nptr);`

@params
	`const char *nptr` The string buffer to convert.

@returns
	`int` The integer representation of the string buffer.

@notes
	The result must be an unsigned long,
	this is to handle overflow and size.
	It is cast to an int when returning,
	therefore if the number is too long
	it will be cut off to an integer.

	Note that the whitespace check uses
	a range and not hard coded variables.

*/

int	ft_atoi(const char *nptr)
{
	int				i;
	int				sign;
	unsigned long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (!nptr)
		return (K0_C_LMA0);
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		++i;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			sign = -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = (result * 10) + (nptr[i++] - '0');
	return ((int)(result * sign));
}
