/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_internal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:50:29 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/01/01 14:26:27 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    ft_syscall

    This module provides a raw assembly
    wrapper over the x86_64 linux kernel.

    Where system calls can be made.
*/

#ifndef FT_INTERNAL_H

# define FT_INTERNAL_H

# include <sys/syscall.h>
# include <sys/sysinfo.h>

long	__syscall(long __flag, ...);

#endif
