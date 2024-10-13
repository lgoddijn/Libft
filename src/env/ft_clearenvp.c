/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clearenvp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:54:02 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/10/13 15:56:31 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_env.h"

int	ft_clearenvp(char ***envp)
{
	char	**e;

	e = *envp;
	*envp = 0;
	if (e)
		while (*e)
			__env_rm_add(*e++, 0);
	return (EXIT_SUCCESS);
}
