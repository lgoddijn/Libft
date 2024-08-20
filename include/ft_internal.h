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

__attribute__((__visibility__("hidden"))) __inline__ void \
	__get_args64(va_list __arg_list, uint64_t __args[6])
{
	int32_t	i;

	i = -1;
	while (++i < 6)
		__args[i] = va_arg(__arg_list, uint64_t);
}

__attribute__((__visibility__("hidden"))) __inline__ void \
	__get_args32(va_list __arg_list, uint32_t __args[5])
{
	int32_t	i;

	i = -1;
	while (++i < 5)
		__args[i] = va_arg(__arg_list, uint32_t);
}

# if defined(__x86_64__)

__inline__ int64_t	__syscall(int64_t __flag, ...);

# elif defined(__aarch64__)

__inline__ int64_t	__syscall(int64_t __flag, ...);

# elif defined(__i386__)

typedef union u_ll_to_int32
{
	int64_t	ll;
	int32_t	l[2];
}	t_ll_to_int32;

__attribute__((__visibility__("hidden"))) \
	static __inline__ void	__syscall_ll_e(
		int64_t __x,
		int32_t *__restricted__ __low,
		int32_t *__restricted__ __high
	)
{
	t_ll_to_int32	conv;

	conv.ll = __x;
	*__low = conv.l[0];
	*__high = conv.l[1];
}

__attribute__((__visibility__("hidden"))) \
	static __inline__ void	__syscall_ll_o(
		int64_t __x,
		int32_t *__restricted__ __low,
		int32_t *__restricted__ __high
	)
{
	__syscall_ll_e(__x, __low, __high);
}

#  if SYSCALL_NO_TLS
#   define SYSCALL_INSNS	"int $128"
#  else
#   define SYSCALL_INSNS	"call *%%gs:16"
#  endif

#  define SYSCALL_INSNS_12	"xchg %%ebx,%%edx ; " SYSCALL_INSNS " ; xchg %%ebx,%%edx"
#  define SYSCALL_INSNS_34	"xchg %%ebx,%%edi ; " SYSCALL_INSNS " ; xchg %%ebx,%%edi"

__inline__ int32_t	__syscall(int32_t __flag, ...);

# elif defined(__arm__)

typedef union u_ll_to_int32
{
	int64_t	ll;
	int32_t	l[2];
}	t_ll_to_int32;

__attribute__((__visibility__("hidden"))) \
	static __inline__ void	__syscall_ll_e(
		int64_t __x,
		int32_t *__restrict__ __low,
		int32_t *__restrict__ __high
	)
{
	t_ll_to_int32	conv;

	conv.ll = __x;
	*__low = conv.l[0];
	*__high = conv.l[1];
}

__attribute__((__visibility__("hidden"))) \
	static __inline__ void	__syscall_ll_o(
		int64_t __x,
		int32_t *__restrict__ __low,
		int32_t *__restrict__ __high
	)
{
	*__low = 0;
	__syscall_ll_e(__x, __low, __high);
}

#  if defined(__thumb__)
#   define __ASM____R7__
#  else
#   define __ASM____R7__	__asm__("r7")
#  endif

#  if defined(__thumb2__)
#   define SYSCALL_OPERAND	"rI"(syscall_number)
#  else
#   define SYSCALL_OPERAND	"r"(syscall_number)
#  endif

__attribute__((__visibility__("hidden"))) static \
	__inline__ int32_t	__asm_syscall(int32_t __nr, ...)
{
	int32_t	r0;
	va_list	args;

	va_start(args, __nr);
	#if defined(__thumb__)
	__asm__(
		"mov r7, %1\n\t"
		"svc 0\n\t"
		: "=r"(r0)
		: "r"(__nr)
		: "r7", "memory"
		);
	#else
	__asm__(
		"svc 0\n\t"
		: "=r"(r0)
		: SYSCALL_OPERAND
		: "memory"
		);
	#endif
	va_end(args);
	return (r0);
}

__inline__ int32_t	__syscall(int32_t __flag, ...);

# else

#  error "Unsupported architecture."

# endif

#endif
