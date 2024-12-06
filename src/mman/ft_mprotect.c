/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mprotect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:45:45 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/14 20:48:58 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_mman.h"

int	ft_mprotect(void *addr, size_t len, int prot)
{
	size_t	start;
	size_t	end;

	start = (size_t)addr & -PAGE_SIZE;
	end = (size_t)((char *)addr + len + PAGE_SIZE - 1) & -PAGE_SIZE;
	return (__syscall3(__NR_mprotect, start, end - start, prot));
}
