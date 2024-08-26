/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mkdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 20:07:08 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/08/26 18:50:26 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

int32_t	ft_mkdir(const char *__path, mode_t __mode)
{
	return ((int32_t)__syscall2(__NR_mkdir, (long)__path, __mode));
}
