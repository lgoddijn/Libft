/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrdir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 15:53:48 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/01/01 15:54:43 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

int	ft_chdir(const char *__path)
{
	if (!__x86_64__)
		return (ARCH_FAIL);
	return (__syscall(__NR_chdir, (long)__path));
}
