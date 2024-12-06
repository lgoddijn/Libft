/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mincore.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:58:42 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/14 19:59:49 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_mman.h"

int	ft_mincore(void *addr, size_t len, unsigned char *vec)
{
	return (__syscall3(__NR_mincore, (long)addr, len, (long)vec));
}
