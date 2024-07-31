/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:32:31 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/31 11:41:30 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_env.h"

char	*ft_getenv(const char *__restrict__ key)
{
	const size_t	l = ft_strchrnul(key, '=') - key;
	char			**e;

	if (l && !key[l] && __environ)
	{
		e = __environ - 1;
		while (*++e)
			if (!ft_strncmp(key, *e, l) && l[*e] == '=')
				return (*e + l + 1);
	}
	return (NULL);
}
