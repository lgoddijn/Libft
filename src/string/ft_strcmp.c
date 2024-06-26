/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:02:07 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/14 18:31:05 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

int32_t	ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 && !s2)
		return (0);
	if (s1 && !s2)
		return ((int32_t)(*s1));
	if (!s1 && s2)
		return (-(int32_t)(*s2));
	while (*s1 == *s2++)
		if (!*s1++)
			return (0);
	return (*(unsigned char *)s1 - \
			*(unsigned char *)--s2);
}
