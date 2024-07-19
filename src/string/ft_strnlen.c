/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:53:56 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/19 11:54:44 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

size_t	ft_strnlen(const char *s, size_t n)
{
	const char	*p = ft_memchr(s, 0, n);

	if (p)
		return (p - s);
	return (n);
}
