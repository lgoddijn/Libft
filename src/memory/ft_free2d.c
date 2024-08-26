/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:22:42 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/17 00:46:37 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_heap.h"

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
