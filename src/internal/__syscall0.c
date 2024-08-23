/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __syscall0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 19:07:12 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/08/21 19:15:51 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_internal.h"

#if defined(__i386__)

__inline__ int32_t	__syscall0(int32_t __nr)
{
	uint32_t	__ret;

	__asm__ (SYSCALL_INSNS : "=a"(__ret) : "a"(__nr) : "memory");
	return ((int32_t)__ret);
}

#elif defined(__x86_64__)

__inline__ int64_t	__syscall0(int64_t __nr)
{
	uint64_t	__ret;

	__asm__ ("syscall" : "=a"(__ret) : "a"(__nr) : "rcx", "r11", "memory");
	return ((int64_t)__ret);
}

#elif defined(__arm__)

__inline int32_t	__syscall0(int32_t __nr)
{
	register int64_t	__ASM____R7__ = n;
	register int64_t	r0 __asm__("r0");

	__asm_syscall(R7_OPERAND);
}

#endif
