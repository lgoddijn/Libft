/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getppid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:48:28 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/01/01 20:42:52 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

pid_t	ft_getppid(void)
{
	if (!__x86_64__)
		return ((pid_t)ARCH_FAIL);
	return ((pid_t)__syscall(__NR_getppid));
}
