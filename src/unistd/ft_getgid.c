/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getgid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:03:10 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/01/01 20:41:24 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

gid_t	ft_getgid(void)
{
	if (!__x86_64__)
		return ((gid_t)ARCH_FAIL);
	return ((gid_t)__syscall(__NR_getgid));
}
