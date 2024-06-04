/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:17:41 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/06/04 17:19:41 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

char	*ft_strtok(char *restrict s, const char *restrict sep)
{
	static char	*p;

	if (!s)
		return (NULL);
	s += ft_strspn(s, sep);
	if (!*s)
	{
		p = 0;
		return (NULL);
	}
	p = s + ft_strcspn(s, sep);
	if (*p)
		*p++ = 0;
	else
		p = 0;
	return (s);
}
