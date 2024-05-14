/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:56:50 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/05/14 13:22:27 by lgoddijn         ###   ########.fr       */
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

bool	ft_isfloat(const char *s)
{
	bool	has_digit;
	bool	has_dot;

	has_digit = false;
	has_dot = false;
	if (!s || !*s)
		return (false);
	while (*s == '-' || *s == '+')
		++s;
	if (!*s)
		return (false);
	while (*s)
	{
		if (*s == '.' && has_dot)
			return (false);
		else if (*s == '.' && !has_dot)
			has_dot = true;
		else if (!ft_isdigit(*s))
			return (false);
		else
			has_digit = true;
		++s;
	}
	return (has_digit);
}
