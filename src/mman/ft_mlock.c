/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:00:10 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/14 20:01:58 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_mman.h"

#ifdef __NR_mlock

int	ft_mlock(const void *addr, size_t len)
{
	return (__syscall2(__NR_mlock, (long)addr, len));
}

#else

int	mlock(const void *addr, size_t len)
{
	return (__syscall2(__NR_mlock2, (long)addr, len));
}

#endif
