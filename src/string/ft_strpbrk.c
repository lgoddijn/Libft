/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:39:27 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/06/04 17:52:26 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

char	*ft_strpbrk(const char *s, const char *b)
{
	if (!s)
		return (NULL);
	s += ft_strcspn(s, b);
	if (*s)
		return ((char *)s);
	return (NULL);
}
