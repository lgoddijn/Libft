/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:36:17 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/06/04 17:56:07 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

char	*ft_strtok_r(
			char *restrict s,
			const char *restrict sep,
			char **restrict p
	)
{
	if (!s)
		return (NULL);
	s += ft_strspn(s, sep);
	if (!*s)
	{
		p = 0;
		return (NULL);
	}
	*p = s + ft_strcspn(s, sep);
	if (**p)
		*(*p)++ = 0;
	else
		*p = 0;
	return (s);
}
