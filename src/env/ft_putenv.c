/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:42:06 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/11 20:56:14 by lgoddijn         ###   ########.fr       */
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

static __inline__ int	__update_existing(char *s, size_t l, char *r, size_t *i)
{
	char		*tmp;
	char		**e;

	*i = 0;
	if (__environ)
	{
		e = __environ;
		while (*e)
		{
			if (!ft_strncmp(s, *e, l + 1))
			{
				tmp = *e;
				*e = s;
				__env_rm_add(tmp, r);
				return (EXIT_SUCCESS);
			}
			++*i;
			++e;
		}
	}
	return (1);
}

static __inline__ int	__do_env_alloc(
		char ***oldenv, char ***newenv,
		size_t i, char *r)
{
	if (__environ == *oldenv)
	{
		*newenv = (char **)ft_realloc(
				*oldenv,
				sizeof(**newenv) * i,
				sizeof(**newenv) * (i + 2));
		if (!*newenv)
		{
			free((void *)r);
			return (-1);
		}
	}
	else
	{
		*newenv = (char **)ft_calloc((i + 2), sizeof(**newenv));
		if (!*newenv)
		{
			free((void *)r);
			return (-1);
		}
		if (i)
			ft_memcpy(*newenv, __environ, sizeof(**newenv) * i);
		free((void *)*oldenv);
	}
	return (EXIT_SUCCESS);
}

int	__ft_putenv(char *s, size_t l, char *r)
{
	static char	**oldenv;
	char		**newenv;
	size_t		i;

	if (__register_cleanup(&oldenv) != 0)
		return (-1);
	if (__update_existing(s, l, r, &i) == 0)
		return (EXIT_SUCCESS);
	if (__do_env_alloc(&oldenv, &newenv, i, r) == -1)
		return (-1);
	newenv[i] = s;
	newenv[i + 1] = 0;
	oldenv = newenv;
	__environ = oldenv;
	if (r)
		__env_rm_add(0, r);
	return (EXIT_SUCCESS);
}

int	ft_putenv(char *s)
{
	const size_t	l = ft_strchrnul(s, '=') - s;

	if (!l || !s[l])
		return (ft_unsetenv(s));
	return (__ft_putenv(s, l, 0));
}
