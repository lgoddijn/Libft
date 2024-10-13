/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clearenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:52:28 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/10/13 15:53:40 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_env.h"

int	ft_clearenv(void)
{
	char	**e;

	e = __environ;
	__environ = 0;
	if (e)
		while (*e)
			__env_rm_add(*e++, 0);
	return (EXIT_SUCCESS);
}
