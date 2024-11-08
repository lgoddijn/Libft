/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putenvp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:00:34 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/08 20:09:31 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_env.h"

static __inline__ int	__update_existing(t_args1 *args)
{
	char		*tmp;
	char		**e;

	args->i = 0;
	if (*(args->__envp))
	{
		e = *(args->__envp);
		while (*e)
		{
			if (!ft_strncmp(args->s, *e, args->l + 1))
			{
				tmp = *e;
				*e = args->s;
				__envp_rm_add(tmp, args->r);
				return (EXIT_SUCCESS);
			}
			++args->i;
			++e;
		}
	}
	return (1);
}

static __inline__ int	__do_env_alloc(
		char ***oldenv,
		char ***newenv,
		t_args2 *args)
{
	if (*(args->__envp) == *oldenv)
	{
		*newenv = (char **)ft_realloc(
			*oldenv,
			sizeof(**newenv) * args->i,
			sizeof(**newenv) * (args->i + 2));
		if (!*newenv)
		{
			free((void *)args->r);
			return (-1);
		}
	}
	else
	{
		*newenv = (char **)malloc(sizeof(**newenv) * (args->i + 2));
		if (!*newenv)
		{
			free((void *)args->r);
			return (-1);
		}
		if (args->i)
			ft_memcpy(*newenv, *(args->__envp), sizeof(**newenv) * args->i);
		free((void *)*oldenv);
	}
	return (EXIT_SUCCESS);
}

int	__ft_putenvp(char *s, size_t l, char *r, char ***__envp)
{
	static char	**oldenv;
	char		**newenv;
	t_args1		args1;
	t_args2		args2;

	args1.s = s;
	args1.r = r;
	args1.i = 0;
	args1.l = l;
	args1.__envp = __envp;
	if (__update_existing(&args1) == 0)
		return (EXIT_SUCCESS);
	args2.i = args1.i;
	args2.r = r;
	args2.__envp = __envp;
	if (__do_env_alloc(&oldenv, &newenv, &args2) == -1)
		return (-1);
	newenv[args2.i] = s;
	newenv[args2.i + 1] = 0;
	oldenv = newenv;
	*__envp = oldenv;
	if (r)
		__env_rm_add(0, r);
	return (EXIT_SUCCESS);
}

int	ft_putenvp(char *s, char ***__envp)
{
	const size_t	l = ft_strchrnul(s, '=') - s;

	if (!l || !s[l])
		return (ft_unsetenvp(s, __envp));
	return (__ft_putenvp(s, l, 0, __envp));
}
