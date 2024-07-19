/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strendswith.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:37:24 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/19 11:00:55 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

bool	ft_strendswith(const char *s, const char *match)
{
	size_t	bytes;

	if (s == match)
		return (true);
	if (!s || !match)
		return (false);
	if (!*match)
		return (true);
	bytes = ft_strlen(match);
	while (*s++)
		;
	while (*s && match && bytes != 0)
		if (*s-- != match[bytes--])
			return (false);
	if (*s == match[bytes])
		return (true);
	return (false);
}
