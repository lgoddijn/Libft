/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenvp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:57:10 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/10/01 14:00:03 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_env.h"

char	*ft_getenvp(const char *__restrict__ key, char *__envp[])
{
	const size_t	l = ft_strchrnul(key, '=') - key;
	char			**e;

	if (l && !key[l] && __envp)
	{
		e = __envp - 1;
		while (*++e)
			if (!ft_strncmp(key, *e, l) && l[*e] == '=')
				return (*e + l + 1);
	}
	return (NULL);
}
