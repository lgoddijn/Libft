/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:44:23 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/05/14 13:10:22 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

bool	ft_isint(const char *s)
{
	if (!s || !*s)
		return (false);
	while (*s == '-'
		|| *s == '+')
		++s;
	if (!*s)
		return (false);
	while (*s)
		if (!ft_isdigit(*s++))
			return (false);
	return (true);
}
