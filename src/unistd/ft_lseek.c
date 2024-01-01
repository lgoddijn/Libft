/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lseek.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 18:07:56 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/01/01 20:44:41 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

/*
	Sadly norminette doesnt allow for preprocessors in this scope
	if a preprocessor statement was useable, llseek operations
	could be implemented in this function depending on the platform.
*/

off_t	ft_lseek(int __fd, off_t __offset, int __whence)
{
	if (!__x86_64__)
		return ((off_t)ARCH_FAIL);
	return (__syscall(__NR_lseek, __fd, __offset, __whence));
}
