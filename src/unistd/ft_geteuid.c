/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_geteuid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:00:15 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/01/01 20:41:14 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

uid_t	ft_geteuid(void)
{
	if (!__x86_64__)
		return ((uid_t)ARCH_FAIL);
	return ((uid_t)__syscall(__NR_geteuid));
}
