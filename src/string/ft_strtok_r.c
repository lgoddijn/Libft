/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:36:17 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/06/06 17:35:22 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

char	*ft_strtok_r(
			char *__restrict__ s,
			const char *__restrict__ sep,
			char **__restrict__ p)
{
	char	*end;

	if (!s)
		return (NULL);
	s += ft_strspn(s, sep);
	if (!*s)
	{
		*p = NULL;
		return (NULL);
	}
	*p = 0;
	end = s + ft_strcspn(s, sep);
	if (*end)
	{
		*end = '\0';
		*p = end + 1;
	}
	return (s);
}
