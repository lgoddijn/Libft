/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:22:42 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/10/13 20:21:31 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_memory.h"

void	ft_free2d(void **ptr)
{
	void	**tmp;

	if (!ptr)
		return ;
	tmp = ptr;
	while (*tmp)
		free((void *)*tmp++);
	free(ptr);
}
