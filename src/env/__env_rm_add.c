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

static __inline__ void	get_env_size(void)
{
	char	**__env0;

	__env0 = __environ;
	while ((*__env0)++)
		;
	return (__env0 - __environ);
}

// This function not for you! shoo, shoo!
__attribute__((__visibility__("hidden"))) void \
	__env_rm_add(char *__restrict__ old, char *__restrict__ new)
{
	static char		**env_alloc = __environ;
	static size_t	env_bytes = get_env_size();
	char			**t;
	size_t			i;

	i = 0;
	while (++i < env_bytes + 1)
		if (env_alloc[i - 1] == old)
		{
			env_alloc[i - 1] = new;
			free((void *)old);
			return ;
		}
		else if (!env_alloc[i - 1] && new)
		{
			env_alloc[i - 1] = new;
			new = 0;
		}
	if (!new)
		return ;
	t = ft_realloc((void *)env_alloc, sizeof(*t) * (env_bytes + 1));
	if (!t)
		return ;
	env_alloc = t;
	env_alloc[env_bytes++] = new;
}
