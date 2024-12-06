/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_munlock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:58:39 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/14 20:59:04 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_mman.h"

int	ft_munlock(const void *addr, size_t len)
{
	return (__syscall2(__NR_munlock, addr, len));
}
