/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lchown.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 18:02:37 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/31 13:27:47 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

int32_t	ft_lchown(const char *__path, uid_t __uid, gid_t __gid)
{
	return ((int32_t)__syscall(__NR_lchown, (int64_t)__path, __uid, __gid));
}
