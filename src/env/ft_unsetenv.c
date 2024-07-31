/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:17:38 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/31 12:35:40 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_env.h"

int32_t	ft_unsetenv(const char *__restrict__ key)
{
	const size_t	l = ft_strchrnul(key, '=') - key;
	char			**eo;
	char			**e;

	if (!l || key[l])
		return (-1);
	if (__environ)
	{
		e = __environ - 1;
		eo = e + 1;
		while (*++e)
		{
			if (!ft_strncmp(key, *e, l) && l[*e] == '=')
				__env_rm_add(*e, 0);
			else if (eo != e)
				*eo++ = *e;
			else
				++eo;
		}
		if (eo != e)
			*eo = 0;
	}
	return (EXIT_SUCCESS);
}
