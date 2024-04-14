/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:08:41 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/14 19:12:03 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

/*

@def
	`ft_itoa.c : ft_itoa`

@brief
	Creates a string buffer containing the digits of the integer `n`.

@description
	Allocates (with `ft_calloc`) and returns a string
	representing the integer received as an argument.
	Negative numbers must be handled.

@synopsis
	`char	*ft_itoa(int n);`

@params 
	`int n` The number to be converted.

@returns
	`char *` The string buffer that represents the number `n`.
	`NULL` If the string buffer allocation fails.

@see
	`ft_calloc.c : ft_calloc`
	`ft_memcpy.c : ft_memcpy`

@extern
	`stdlib.h : malloc(3)`

@notes
	Because `abs(INT_MIN)` is larger than `INT_MAX`
	the first thin the function does is check for the edge case.

	The buffer is filled backwards, so the first thing added is `\0`.

	The school would like a recursive approach,
	but I find this to be more efficient and safer.

	The function uses `ft_strdup` because the return value
	must always be freeable, and `ft_strdup` uses `malloc(3)`.

	I wrote this function ages ago (I hate it and its terrible).

*/

char	*ft_itoa(int32_t n)
{
	char	*alloc;
	size_t	len;
	bool	is_neg;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	is_neg = false;
	len = 0;
	if (n < 0)
		is_neg = true;
	len = ft_digits((int64_t)n);
	alloc = (char *)ft_calloc(len + 1, sizeof(char));
	if (!alloc)
		return (NULL);
	while (n != 0 && --len)
	{
		alloc[len] = \
		(n % 10) + '0';
		n /= 10;
	}
	if (is_neg)
		alloc[len] = '-';
	return (alloc);
}
