/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __env_rm_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:05:49 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/08 20:05:36 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_env.h"

static __always_inline int	__register_cleanup(char ***alloc)
{
	static int	registered = 0;

	if (!registered)
	{
		if (ft_atexit(__free2d_env_alloc, (void *)alloc) != 0)
			return (-1);
		registered = 1;
	}
	return (EXIT_SUCCESS);
}

static __always_inline t_rmadd_ret	__loop(
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
			return (RETURN);
		}
		else if (!alloc[i - 1] && *new)
		{
			alloc[i - 1] = *new;
			*new = 0;
		}
	}
	return (NARET);
}

void	__env_rm_add(char *old, char *new)
{
	static char		**alloc;
	static size_t	env_n;
	char			**t;

	if (__register_cleanup(&alloc) != 0)
		return ;
	if (__loop(
			alloc,
			env_n,
			&old,
			&new) == RETURN)
		return ;
	if (!new)
		return ;
	t = (char **)ft_realloc(
			alloc, sizeof(*t) * env_n,
			sizeof(*t) * (env_n + 1));
	if (!t)
		return ;
	alloc = t;
	alloc[env_n++] = new;
}
