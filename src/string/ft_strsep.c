/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:19:34 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/07 17:23:26 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

/* Like strsplit, minus the heap. */
char	*ft_strsep(char **str, const char *sep)
{
	char	*s;
	char	*end;

	s = *str;
	if (!s)
		return (NULL);
	end = s + ft_strcspn(s, sep);
	if (*end)
		*end++ = 0;
	else
		end = NULL;
	*str = end;
	return (s);
}
