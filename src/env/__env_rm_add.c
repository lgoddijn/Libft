/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __env_rm_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:05:49 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/10/13 18:17:37 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_env.h"

static __inline__ void	__loop(
		char **alloc, size_t env_n,
		char **__restrict__ old,
		char **__restrict__ new)
{
	size_t	i;

	i = 0;
	while (++i < env_n + 1)
	{
		if (alloc[i - 1] == *old)
		{
			alloc[i - 1] = *new;
			free((void *)*old);
			return ;
		}
		else if (!alloc[i - 1] && *new)
		{
			alloc[i - 1] = *new;
			*new = 0;
		}
	}
}

void	__env_rm_add(char *old, char *new)
{
	static char		**alloc;
	static size_t	env_n;
	char			**t;

	__loop(
		alloc,
		env_n,
		&old,
		&new);
	if (!new)
		return ;
	t = (char **)ft_realloc(
			alloc, sizeof(*t) \
			* (env_n + 1));
	if (!t)
		return ;
	alloc = t;
	alloc[env_n++] = new;
}
