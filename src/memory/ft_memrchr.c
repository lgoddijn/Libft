/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:48:26 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/08 20:01:31 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_memory.h"

void	*ft_memrchr(const void *m, int c, size_t n)
{
	register const unsigned char	*s = m;

	if (!m || !n)
		return (NULL);
	c = (unsigned char)c;
	while (n--)
		if (s[n] == c)
			return ((void *)(s + n));
	return (NULL);
}
