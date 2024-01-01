/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lchown.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 18:02:37 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/01/01 20:44:04 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

int	ft_lchown(const char *__path, uid_t __uid, gid_t __gid)
{
	if (!__x86_64__)
		return (ARCH_FAIL);
	return ((int)__syscall(__NR_lchown, (long)__path, __uid, __gid));
}
