/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 12:16:23 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 12:16:23 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_heap.h"

static t_bitmask64	get_offset_mask(void)
{
	return (0xfffULL | (~((1ULL << (64 - (12 + 8 \
		* (sizeof(off_t) - sizeof(long))))) - 1)));
}

void	*ft_mmap(
	size_t __size,
	int __prot,
	int __flags,
	off_t __offset
	)
{
	void	*out;

	if (__offset & get_offset_mask())
		return (MAP_FAILED);
	if (__size >= PTRDIFF_MAX)
		return (MAP_FAILED);
	if (__x86_64__)
	{
		out = (void *)__syscall(__NR_mmap, NULL,
				__size, __prot, __flags, -1, __offset);
		if (out == MAP_FAILED || out == NULL)
			return (MAP_FAILED);
		if ((unsigned long)out >= (unsigned long) - 1 - 4096)
			return (MAP_FAILED);
		return (out);
	}
	return (MAP_FAILED);
}
