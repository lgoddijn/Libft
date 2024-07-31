/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:25:22 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/31 13:28:32 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

ssize_t	ft_read(int32_t __fd, const void *__buf, size_t __size)
{
	return ((ssize_t)__syscall(__NR_read, __fd, __buf, __size));
}
