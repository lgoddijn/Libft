/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:03:52 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/17 21:07:24 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_mman.h"

#ifdef __NR_mmap2

void	*ft_mmap(t_mmap_args args)
{
	if (args.offset & (((-(MMAP2_PAGE_UNIT << 1)
		<< (8 * sizeof (off_t) - 1))) | (MMAP2_PAGE_UNIT - 1)))
	{
		errno = EINVAL;
		return (MAP_FAILED);
	}
	if (args.len >= PTRDIFF_MAX)
	{
		errno = ENOMEM;
		return (MAP_FAILED);
	}
	if (args.flags & MAP_FIXED)
		__vm_wait();
	return ((void *)__syscall6(__NR_mmap2, (long [6]){
			args.addr, args.len, args.prot, args.flags,
			args.fd, (args.offset / MMAP2_PAGE_UNIT)
	}));
}

#else

void	*ft_mmap(t_mmap_args args)
{
	if (args.offset & (0x0 | (MMAP2_PAGE_UNIT - 1)))
	{
		errno = EINVAL;
		return (MAP_FAILED);
	}
	if (args.len >= PTRDIFF_MAX)
	{
		errno = ENOMEM;
		return (MAP_FAILED);
	}
	if (args.flags & MAP_FIXED)
		__vm_wait();
	return ((void *)__syscall6(__NR_mmap, (long [6]){
			args.addr, args.len, args.prot,
			args.flags, args.fd, args.offset
	}));
}

#endif
