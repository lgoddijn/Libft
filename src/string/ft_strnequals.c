/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:12:09 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/16 19:14:36 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

bool	ft_strnequals(const char *lhs, const char *rhs, size_t n)
{
	if (lhs == rhs)
		return (true);
	if (!lhs || !rhs)
		return (false);
	while (*lhs && *rhs && --n > 0)
		if (*lhs++ != *rhs++)
			return (false);
	if (*lhs == *rhs)
		return (true);
	return (false);
}
