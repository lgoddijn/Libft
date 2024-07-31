/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_internal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:50:29 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/31 14:01:53 by lgoddijn         ###   ########.fr       */
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

# ifndef __NR_readlink
#  define __READLINK_NR	__NR_readlinkat
# else
#  define __READLINK_NR	__NR_readlink
# endif


# if defined(__x86_64__)

int64_t	__syscall(int64_t __flag, ...);

# elif defined(__aarch64__)

int64_t	__syscall(int64_t __flag, ...);

# elif defined(__i386__)

int32_t	__syscall(int32_t __flag, ...);

# elif defined(__arm__)

int32_t	__syscall(int32_t __flag, ...);

# else

#  error "Unsupported architecture."

# endif

#endif
