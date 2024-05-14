/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:56:50 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/05/14 14:03:58 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

/*

	Note that this function (by design)
	doesn't care where the '.' is positioned,
	nor does it care if the number is an integer.

	This is because values like .4 and 7 can 
	just be interpreted then as 0.4 and 7.0

*/

int32_t	ft_isfloat(const char *s)
{
	int32_t	has_digit;
	int32_t	has_dot;

	has_digit = 0;
	has_dot = 0;
	if (!s || !*s)
		return (0);
	while (*s == '-' || *s == '+')
		++s;
	if (!*s)
		return (0);
	while (*s)
	{
		if (*s == '.' && has_dot)
			return (0);
		else if (*s == '.' && !has_dot)
			has_dot = 1;
		else if (!ft_isdigit(*s))
			return (0);
		else
			has_digit = 1;
		++s;
	}
	return (has_digit);
}
