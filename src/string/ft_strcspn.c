/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:05:23 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/06/04 17:53:58 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

static bool	byte_is_valid(size_t bset[32 / sizeof(size_t)], unsigned char byte)
{
	return ((bset)[(size_t)(byte) / (8 * sizeof *(bset))] &
		(size_t)1 << ((size_t)(byte) % (8 * sizeof *(bset))));
}

static bool	populate_set(size_t bset[32 / sizeof(size_t)], unsigned char byte)
{
	return ((bset)[(size_t)(byte) / (8 * sizeof *(bset))] |=
		(size_t)1 << ((size_t)(byte) % (8 * sizeof *(bset))));
}

size_t	ft_strcspn(const char *s, const char *set)
{
	size_t		bset[32 / sizeof(size_t)];
	const char	*a = s;

	if (!s || !s[0])
		return (0);
	if (!set[0] || !set[1])
		return (ft_strchrnul(s, *set) - a);
	ft_bzero((void *)bset, sizeof(bset));
	while (*set && populate_set(bset,
			*(unsigned char *)set) && ++set)
		;
	while (*s && !byte_is_valid(bset,
			*(unsigned char *)s && ++s))
		;
	return (s - a);
}
