/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscall.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:50:29 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/08 19:52:48 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SYSCALL_H

# define FT_SYSCALL_H

# include <sys/syscall.h>
# include <sys/sysinfo.h>
# include <stdint.h>
# include <stdarg.h>
# include <errno.h>

# define __INTERNAL_SYSCALL_EXTEND
# include "ft_syscall2.h"
# undef __INTERNAL_SYSCALL_EXTEND

static __always_inline long	__syscall0(long n)
{
	register unsigned long	r;

	__asm__ ("syscall" : "=a"(r) : "a"(n) : "rcx", "r11", "memory");
	return (__syscall_r(r));
}

static __always_inline long	__syscall1(long n, long a1)
{
	register unsigned long	r;

	__asm__ (
		"syscall" : "=a"(r) : "a"(n), "D"(a1)
		: "rcx", "r11", "memory");
	return (__syscall_r(r));
}

static __always_inline long	__syscall2(long n, long a1, long a2)
{
	register unsigned long	r;

	__asm__ (
		"syscall" : "=a"(r) : "a"(n), "D"(a1),
		"S"(a2) : "rcx", "r11", "memory");
	return (__syscall_r(r));
}

static __always_inline long	__syscall3(long n, long a1, long a2, long a3)
{
	register unsigned long	r;

	__asm__ (
		"syscall" : "=a"(r) : "a"(n), "D"(a1),
		"S"(a2), "d"(a3) : "rcx", "r11", "memory");
	return (__syscall_r(r));
}

#endif
