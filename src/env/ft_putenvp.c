/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putenvp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:00:34 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/10/13 17:41:12 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_env.h"

static __inline__ int	handle_new_env(
		char **__restrict__ new,
		char *__restrict__ r,
		size_t i,
		char ***__envp
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
			(const void *)*__envp,
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
		size_t i,
		char ***__envp
	)
{
	static char	**old;
	char		**new;

	new = NULL;
	if (*__envp == old
		&& handle_old_env(old, new, r, i) != EXIT_SUCCESS)
		return (-1);
	else
	{
		if (handle_new_env(new, r, i, __envp) != EXIT_SUCCESS)
			return (-1);
		free((void *)old);
	}
	new[i] = s;
	new[i + 1] = 0;
	old = new;
	*__envp = old;
	if (r)
		__env_rm_add(NULL, r);
	return (EXIT_SUCCESS);
}

int	ft_putenvp_heap(
		char *__restrict__ s,
		char *__restrict__ r,
		char ***__envp)
{
	const size_t	l = ft_strchrnul(s, '=') - s;
	char			*tmp;
	char			**e;
	size_t			i;

	i = 0;
	if (!l || !s[l])
		return (ft_unsetenv(s));
	if (*__envp)
	{
		e = *__envp - 1;
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
	return (handle_env_alloc(s, r, i, __envp));
}

int	ft_putenvp(char *__restrict__ s, char ***__envp)
{
	return (ft_putenvp_heap(s, NULL, __envp));
}
