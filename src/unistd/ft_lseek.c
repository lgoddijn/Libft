/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lseek.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 18:07:56 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/08/26 19:03:37 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

#if defined(__NR_llseek)

off_t	ft_lseek(int32_t __fd, off_t __offset, int32_t __whence)
{
	const off_t	r = __syscall5(__NR_llseek, (long [5]){
			__fd,
			__offset >> 32,
			__offset,
			&r,
			__whence});

	if (r)
		return (r);
	return (-1);
}

#else

off_t	ft_lseek(int32_t __fd, off_t __offset, int32_t __whence)
{
	return ((off_t)__syscall3(__NR_lseek, __fd, __offset, __whence));
}

#endif
