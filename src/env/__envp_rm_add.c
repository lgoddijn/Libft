/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __envp_rm_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:11:32 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/10/01 15:10:04 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_env.h"

static __inline__ void	get_env_size(char *__envp[])
{
	char	**__envp0;

	__envp0 = __envp;
	while ((*__envp)++)
		;
	return (__envp - __envp0);
}

// This function not for you! shoo, shoo!
__attribute__((__visibility__("hidden"))) void \
	__envp_rm_add(char *__restrict__ old, char *__restrict__ new, char *__envp[])
{
	static size_t	env_size = get_env_size(__envp);
	char			**t;
	size_t			i;

	i = 0;

	while (++i < env_size + 1)
		if (__envp[i - 1] == old)
		{
			__envp[i - 1] = new;
			free((void *)old);
			return ;
		}
		else if (!__envp[i - 1] && new)
		{
			__envp[i - 1] = new;
			new = 0;
		}
	if (!new)
		return ;
	t = ft_realloc((void *)__envp, sizeof(*t) * (env_size + 1));
	if (!t)
		return ;
	__envp = t;
	__envp[env_size++] = new;
}
