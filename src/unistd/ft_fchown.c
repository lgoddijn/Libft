/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fchown.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:32:22 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/08/26 18:48:50 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

int32_t	ft_fchown(int32_t __fd, uid_t __uid, gid_t __gid)
{
	return ((int32_t)__syscall3(__NR_fchown, __fd, __uid, __gid));
}
