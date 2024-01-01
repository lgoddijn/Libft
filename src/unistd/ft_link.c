/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 18:04:48 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/01/01 20:44:15 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

int	ft_link(const char *__existing, const char *__new)
{
	if (!__x86_64__)
		return (ARCH_FAIL);
	return ((int)__syscall(__NR_link, (long)__existing, (long)__new));
}
