/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenvp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:05:55 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/10/14 17:20:52 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_env.h"

int	ft_setenvp(
	const char *var,
	const char *value,
	int overwrite,
	char ***__envp)
{
	char	*s;
	size_t	l1;
	size_t	l2;

	l1 = ft_strchrnul(var, '=') - var;
	if (!var || !l1 || var[l1])
		return (-1);
	if (!overwrite && ft_getenv(var))
		return (0);
	l2 = ft_strlen(value);
	s = (char *)malloc(l1 + l2 + 2);
	if (!s)
		return (-1);
	ft_memcpy(s, var, l1);
	s[l1] = '=';
	ft_memcpy(s + l1 + 1, value, l2 + 1);
	return (__ft_putenvp(s, l1, s, __envp));
}
