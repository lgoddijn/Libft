/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:50:22 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/05/14 15:12:06 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

/*

@def
	`ft_atoi.c : ft_atoi`

@brief
	Converts a string buffer to an integer.

@man
    The  atoi() function converts the initial portion of the string pointed
    to by s to int.  The behavior is the same as

        strtol(s, NULL, 10);

    Except that atoi() does not detect errors.

@synopsis
	`int	ft_atoi(const char *s);`

@params
	`const char *s` The string buffer to convert.

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

int32_t	ft_atoi(const char *s)
{
	int32_t		i;
	int32_t		sign;
	uint64_t	result;

	i = 0;
	sign = 1;
	result = 0;
	if (!s || !ft_isint(s))
		return ((int32_t)K0_C_LMA0);
	while (ft_isspace((int32_t)s[i]))
		++i;
	while (s[i] == '-'
		|| s[i] == '+')
		if (s[i++] == '-')
			sign *= -1;
	while (s[i])
		result = (result * 10) + (s[i++] - '0');
	return ((int32_t)(result * sign));
}
