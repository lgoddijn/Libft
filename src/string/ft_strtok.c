/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:17:41 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/06/06 17:30:23 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

char	*ft_strtok(
	char *__restrict__ s,
	const char *__restrict__ sep
)
{
	static char	*p;

	if (s)
		p = s;
	else if (!p)
		return (NULL);
	p += ft_strspn(p, sep);
	if (!*p)
	{
		p = NULL;
		return (NULL);
	}
	s = p;
	p += ft_strcspn(p, sep);
	if (*p)
		*p++ = '\0';
	else
		p = NULL;
	return (s);
}
