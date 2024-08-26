/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscall.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:50:29 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/08/26 19:00:13 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SYSCALL_H

# define FT_SYSCALL_H

# include <sys/syscall.h>
# include <sys/sysinfo.h>
# include <stdint.h>
# include <stdarg.h>

# if defined(__x86_64__)

static __always_inline long	__syscall0(long n)
{
	unsigned long	r;

	__asm__ ("syscall" : "=a"(r) : "a"(n) : "rcx", "r11", "memory");
	return ((long)r);
}

static __always_inline long	__syscall1(long n, long a1)
{
	unsigned long	r;

	__asm__ (
		"syscall" : "=a"(r) : "a"(n), "D"(a1)
		: "rcx", "r11", "memory");
	return ((long)r);
}

static __always_inline long	__syscall2(long n, long a1, long a2)
{
	unsigned long	r;

	__asm__ (
		"syscall" : "=a"(r) : "a"(n), "D"(a1),
		"S"(a2) : "rcx", "r11", "memory");
	return ((long)r);
}

static __always_inline long	__syscall3(long n, long a1, long a2, long a3)
{
	unsigned long	r;

	__asm__ (
		"syscall" : "=a"(r) : "a"(n), "D"(a1),
		"S"(a2), "d"(a3) : "rcx", "r11", "memory");
	return ((long)r);
}

long	__syscall4(long n, long a[4]);
long	__syscall5(long n, long a[5]);
long	__syscall6(long n, long a[6]);

# else

#  error "Only 64-bit x86_64 Little Endian architecture supported"

# endif

#endif
