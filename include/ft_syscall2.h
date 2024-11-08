/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscall2.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:59:23 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/08 13:59:33 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SYSCALL2_H

# define FT_SYSCALL2_H

# ifndef __INTERNAL_SYSCALL_EXTEND
#  error "Include `ft_syscall.h` instead."
# endif

static __always_inline long	__syscall_r(unsigned long r)
{
	if (r > -4096UL)
	{
		errno = -r;
		return (-1);
	}
	return (r);
}

static __always_inline long	__syscall4(long n, long a[4])
{
	register const long r10	__asm__("r10") = a[3];
	register unsigned long	r;

	__asm__ (
		"syscall" : "=a"(r) : "a"(n), "D"(a[0]), "S"(a[1]),
		"d"(a[2]), "r"(r10) : "rcx", "r11", "memory");
	return (__syscall_r(r));
}

static __always_inline long	__syscall5(long n, long a[5])
{
	register const long r10	__asm__("r10") = a[3];
	register const long r8	__asm__("r8") = a[4];
	register unsigned long	r;

	__asm__ (
		"syscall" : "=a"(r) : "a"(n), "D"(a[0]), "S"(a[1]),
		"d"(a[2]), "r"(r10), "r"(r8) : "rcx", "r11", "memory");
	return (__syscall_r(r));
}

static __always_inline long	__syscall6(long n, long a[6])
{
	register const long r10	__asm__("r10") = a[3];
	register const long r8	__asm__("r8") = a[4];
	register const long r9	__asm__("r9") = a[5];
	register unsigned long	r;

	__asm__ (
		"syscall" : "=a"(r) : "a"(n), "D"(a[0]), "S"(a[1]), "d"(a[2]),
		"r"(r10), "r"(r8), "r"(r9) : "rcx", "r11", "memory");
	return (__syscall_r(r));
}

#endif
