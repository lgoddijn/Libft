/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getegid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:57:45 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/01/01 20:40:59 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

gid_t	ft_getegid(void)
{
	if (!__x86_64__)
		return ((gid_t)ARCH_FAIL);
	return ((gid_t)__syscall(__NR_getegid));
}
