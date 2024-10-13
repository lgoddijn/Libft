/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:42:06 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/10/13 17:37:47 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_env.h"

static __inline__ int	handle_new_env(
		char **__restrict__ new,
		char *__restrict__ r,
		size_t i
	)
{
	new = (char **)malloc(sizeof(*new) * (i + 2));
	if (!new)
	{
		if (r)
			free((void *)r);
		return (-1);
	}
	if (i)
		ft_memcpy(
			(void *)new,
			(const void *)__environ,
			sizeof(*new) * i);
	return (EXIT_SUCCESS);
}

static __inline__ int	handle_old_env(
		char **__restrict__ old,
		char **__restrict__ new,
		char *__restrict__ r,
		size_t i
	)
{
	new = (char **)ft_realloc((void *)old, sizeof(*new) * (i + 1));
	if (!new)
	{
		if (r)
			free((void *)r);
		return (-1);
	}
	return (EXIT_SUCCESS);
}

static __inline__ int	handle_env_alloc(
		char *__restrict__ s,
		char *__restrict__ r,
		size_t i
	)
{
	static char	**old;
	char		**new;

	new = NULL;
	if (__environ == old
		&& handle_old_env(old, new, r, i) != EXIT_SUCCESS)
		return (-1);
	else
	{
		if (handle_new_env(new, r, i) != EXIT_SUCCESS)
			return (-1);
		free((void *)old);
	}
	new[i] = s;
	new[i + 1] = 0;
	old = new;
	__environ = old;
	if (r)
		__env_rm_add(NULL, r);
	return (EXIT_SUCCESS);
}

int	ft_putenv_heap(char *__restrict__ s, char *__restrict__ r)
{
	const size_t	l = ft_strchrnul(s, '=') - s;
	char			*tmp;
	char			**e;
	size_t			i;

	i = 0;
	if (!l || !s[l])
		return (ft_unsetenv(s));
	if (__environ)
	{
		e = __environ - 1;
		while (*++e && ++i)
		{
			if (!ft_strncmp(s, *e, l + 1))
			{
				tmp = *e;
				*e = s;
				__env_rm_add(tmp, 0);
			}
		}
	}
	return (handle_env_alloc(s, r, i));
}

int	ft_putenv(char *__restrict__ s)
{
	return (ft_putenv_heap(s, NULL));
}
