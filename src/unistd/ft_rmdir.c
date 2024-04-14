/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rmdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 18:40:40 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/14 18:41:53 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

int32_t	ft_rmdir(const char *__path)
{
	if (!__x86_64__)
		return (ARCH_FAIL);
	return ((int32_t)__syscall(__NR_rmdir, (int64_t)__path));
}
