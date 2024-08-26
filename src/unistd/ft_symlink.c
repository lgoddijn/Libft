/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_symlink.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 18:47:27 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/08/26 18:50:58 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

int32_t	ft_symlink(const char *__existing, const char *__new)
{
	return ((int32_t)__syscall2(__NR_symlink,
			(long)__existing,
			(long)__new));
}
