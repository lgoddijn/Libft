/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpgid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:32:03 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/01/01 20:42:02 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

pid_t	ft_getpgid(pid_t pid)
{
	if (!__x86_64__)
		return ((pid_t)ARCH_FAIL);
	return ((pid_t)__syscall(__NR_getpgid, pid));
}
