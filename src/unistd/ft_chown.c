/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chown.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 15:59:00 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/31 13:24:48 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

int32_t	ft_chown(const char *__path, uid_t __uid, gid_t __gid)
{
	return ((int32_t)__syscall(__NR_chown, (int64_t)__path, __uid, __gid));
}
