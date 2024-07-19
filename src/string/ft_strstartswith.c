/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstartswith.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:34:56 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/19 11:06:50 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

bool	ft_strstartswith(const char *s, const char *match)
{
	if (s == match)
		return (true);
	if (!s || !match)
		return (false);
	while (*s && *match)
		if (*s++ != *match++)
			return (false);
	if (*s && !*match)
		return (true);
	if (!*s && *match)
		return (false);
	if (*s == *match)
		return (true);
	return (false);
}
