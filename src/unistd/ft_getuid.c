/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getuid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:52:37 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/01/01 20:43:43 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

uid_t	ft_getuid(void)
{
	if (!__x86_64__)
		return ((uid_t)ARCH_FAIL);
	return ((uid_t)__syscall(__NR_getuid));
}
