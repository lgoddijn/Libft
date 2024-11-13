/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __cleanup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:15:04 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/13 14:11:44 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_env.h"

/* Expecting ref to 2d allocated structure */
void	__free2d_env_alloc(void *alloc)
{
	char	***a;
	char	**e;

	a = (char ***)alloc;
	if (*a)
	{
		e = *a;
		while (*e)
			free(*e++);
		free(*a);
		*a = 0;
	}
}
