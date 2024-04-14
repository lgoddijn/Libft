/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_internal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:50:29 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/14 18:46:14 by lgoddijn         ###   ########.fr       */
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
# include <stdint.h>
# include <stdarg.h>

int64_t	__syscall(int64_t __flag, ...);

#endif
