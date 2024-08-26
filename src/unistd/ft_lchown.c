/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lchown.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 18:02:37 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/08/26 18:50:07 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

int32_t	ft_lchown(const char *__path, uid_t __uid, gid_t __gid)
{
	return ((int32_t)__syscall3(__NR_lchown, (long)__path, __uid, __gid));
}
