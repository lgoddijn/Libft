/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenvp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:07:13 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/11 20:57:33 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_env.h"

int	ft_unsetenvp(const char *__restrict__ key, char ***__envp)
{
	const size_t	l = ft_strchrnul(key, '=') - key;
	char			**eo;
	char			**e;

	if (!l || key[l])
		return (-1);
	if (*__envp)
	{
		e = *__envp - 1;
		eo = e + 1;
		while (*++e)
		{
			if (!ft_strncmp(key, *e, l) && l[*e] == '=')
				__envp_rm_add(*e, 0);
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
