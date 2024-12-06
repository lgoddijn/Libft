/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msync.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:57:35 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/14 20:58:07 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_mman.h"

int	ft_msync(void *start, size_t len, int flags)
{
	return (__syscall3(__NR_msync, start, len, flags));
}
