/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:23:49 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/08 20:19:08 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_memory.h"

void	*ft_realloc(void *p, size_t psize, size_t size)
{
	void	*alloc;

	if (!size && p)
	{
		free((void *)p);
		return (NULL);
	}
	if (!p)
		return (malloc(size));
	if (size >= SIZE_MAX / 2 - 4096)
		return (NULL);
	alloc = malloc(size);
	if (!alloc)
		return (NULL);
	ft_memcpy(alloc, p, psize);
	free((void *)p);
	return (alloc);
}
