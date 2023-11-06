/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:08:41 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/11/06 14:33:30 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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

static size_t	n_len(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		++len;
	while (n != 0)
	{
		++len;
		n /= 10;
	}
	return (len);
}

static void	fill_buffer(char *buff, int n,
				bool is_neg, size_t len)
{
	buff[len] = '\0';
	while (n != 0)
	{
		buff[--len] = (n % 10) + '0';
		n /= 10;
	}
	if (is_neg)
		buff[len] = '-';
}

char	*ft_itoa(int n)
{
	char	*alloc;
	size_t	len;
	bool	is_neg;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len = 0;
	if (n < 0)
	{
		is_neg = true;
		n = -n;
		++len;
	}
	else
		is_neg = false;
	len = n_len(n);
	alloc = (char *)ft_calloc(len + 1, sizeof(char));
	if (alloc == NULL)
		return (NULL);
	fill_buffer(alloc, n, is_neg, len);
	return (alloc);
}
