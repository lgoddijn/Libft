/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_symlink.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 18:47:27 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/01/01 18:50:10 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

int	ft_symlink(const char *__existing, const char *__new)
{
	if (!__x86_64__)
		return (ARCH_FAIL);
	return ((int)__syscall(
			__NR_symlink,
			(long)__existing,
			(long)__new));
}
