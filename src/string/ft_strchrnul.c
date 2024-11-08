/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrnul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:22:01 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/06/04 17:50:55 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

char	*ft_strchrnul(const char *s, int c)
{
	register const t_word	*w;
	register size_t			k;

	c = (unsigned char)c;
	if (!c)
		return ((char *)s + ft_strlen(s));
	while ((uintptr_t)s++ & sizeof(size_t))
		if (!*(s - 1) || *(unsigned char *)(s - 1) == c)
			return ((char *)(s - 1));
	k = ((size_t) - 1 / UCHAR_MAX) * c;
	w = (void *)s;
	while (!((*w) - ((size_t) - 1 / UCHAR_MAX) & ~(*w)
			& (((size_t) - 1 / UCHAR_MAX) * (UCHAR_MAX / 2 + 1)))
		&& !((*w ^ k) - ((size_t) - 1 / UCHAR_MAX) & ~(*w ^ k)
			& (((size_t) - 1 / UCHAR_MAX) * (UCHAR_MAX / 2 + 1))))
		++w;
	s = (void *)w;
	while (*s && *(unsigned char *)s != c)
		++s;
	return ((char *)s);
}
