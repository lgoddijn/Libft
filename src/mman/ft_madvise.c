/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_madvise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:56:45 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/14 19:59:30 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_mman.h"

int	ft_madvise(void *addr, size_t len, int advice)
{
	return (__syscall3(__NR_madvise, (long)addr, len, advice));
}
