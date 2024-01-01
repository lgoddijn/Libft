/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:54:01 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:10:48 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

/*

@def
	`ft_strequals.c : ft_strequals`

@brief
	Checks if two strings are identical.

@description
    Checks if two strings are identical.
	This includes pointer values, and `NULL`.
	You could think of this function as
	`str1 == str2`.

@synopsis
	`bool	ft_strequals(const char *lhs, const char *rhs);`

@params
	`const char *lhs` The left hand string.
	`const char *rhs` The right hand string.

@return
	`bool` Wheather the two strings are equal or not.

@notes
	The function has multiple checks for all kinds of
	arguments, including pointers, `NULL` and obviously
	the regular string arguments. Note that the first
	pointer check accounts for `NULL` as well.
	Therefore the second "or" check doesnt need
	to account for them both being `NULL`.

*/

bool	ft_strequals(const char *lhs, const char *rhs)
{
	if (lhs == rhs)
		return (true);
	if (!lhs || !rhs)
		return (false);
	while (*lhs && *rhs)
		if (*lhs++ != *rhs++)
			return (false);
	if (*lhs == *rhs)
		return (true);
	return (false);
}
