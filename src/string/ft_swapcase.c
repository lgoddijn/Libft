/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapcase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:23:38 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/06/27 15:41:32 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

static void	build_map(char *map)
{
	char	c;

	c = 'A' - 1;
	ft_bzero(map, 256);
	while (++c <= 'Z')
	{
		map[(unsigned char)c] = c + 32;
		map[(unsigned char)c + 32] = c;
	}
}

char	*ft_swapcase(const char *s)
{
	const size_t	len = ft_strlen(s);
	char			map[256];
	char			*result;
	size_t			i;

	if (s == NULL)
		return (NULL);
	build_map(map);
	result = (char *)malloc(len + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (++i < len + 1)
	{
		if (ft_isalpha((unsigned char)s[i - 1]))
			result[i - 1] = map[(unsigned char)s[i - 1]];
		else
			result[i - 1] = s[i - 1];
	}
	result[len] = '\0';
	return (result);
}
