/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __env_rm_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:05:49 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/31 12:30:14 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_env.h"

static __inline__ void	do_realloc(
	char **__restrict__ env_alloc,
	char *__restrict__ new,
	size_t env_bytes
	)
{
	char	**t;

	if (!new)
		return ;
	t = (char **)ft_realloc(
			(void *)env_alloc,
			sizeof(*t) * (env_bytes + 1));
	if (!t)
		return ;
	env_alloc = t;
	env_alloc[env_bytes++] = new;
}

// This function not for you! shoo, shoo!
__attribute__((__visibility__("hidden"))) void \
	__env_rm_add(char *__restrict__ old, char *__restrict__ new)
{
	static char		**env_alloc;
	static size_t	env_bytes;
	size_t			i;

	i = 0;
	while (i < env_bytes)
	{
		if (env_alloc[i] == old)
		{
			env_alloc[i] = new;
			free((void *)old);
			return ;
		}
		if (!env_alloc[i] && new)
		{
			env_alloc[i] = new;
			new = 0;
		}
	}
	do_realloc(env_alloc, new, env_bytes);
}
