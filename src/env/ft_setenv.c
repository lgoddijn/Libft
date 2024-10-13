/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:22:31 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/10/13 18:04:06 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_env.h"

int	ft_setenv(const char *__restrict__ key, const char *__restrict__ value)
{
	const size_t	l1 = ft_strchrnul(key, '=') - key;
	const size_t	l2 = ft_strlen(value);
	char			*s;
	char			*s2;
	int32_t			ret;

	if (!key || !l1 || key[l1])
		return (-1);
	s = (char *)malloc(l1 + l2 + 2);
	if (!s)
		return (-1);
	ft_memcpy((void *)s, (const void *)key, l1);
	ft_memcpy((void *)(s + l1 + 1), (const void *)value, l2 + 1);
	s[l1] = '=';
	s2 = ft_strdup(s);
	if (!s2)
	{
		free((void *)s);
		return (-1);
	}
	ret = ft_putenv_heap(s, s2);
	if (s2)
		free((void *)s2);
	return (ret);
}
