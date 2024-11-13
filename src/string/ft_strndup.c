/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:13:02 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/13 01:16:35 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

char	*ft_strndup(const char *s, size_t n)
{
	const size_t	l = ft_strnlen(s, n);

	return (ft_memcpy((char *)ft_calloc(
				l + 1, sizeof(char)), s, l));
}
