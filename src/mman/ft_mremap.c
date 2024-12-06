/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mremap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:49:21 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/17 21:08:28 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_mman.h"

void	*ft_mremap(t_mremap_args args)
{
	if (args.new_len >= PTRDIFF_MAX)
	{
		errno = ENOMEM;
		return (MAP_FAILED);
	}
	if (args.flags & MREMAP_FIXED)
		__vm_wait();
	return ((void *)__syscall5(__NR_mremap, (long [5]){
			args.old_addr, args.old_len, args.new_len,
			args.flags, args.new_addr
	}));
}
