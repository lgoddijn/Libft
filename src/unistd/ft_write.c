/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:03:56 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/08/26 18:51:13 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

ssize_t	ft_write(int32_t __fd, const void *__buf, size_t __size)
{
	return ((ssize_t)__syscall3(__NR_write, __fd, (long)__buf, (long)__size));
}
