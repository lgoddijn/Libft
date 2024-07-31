/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __syscall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 18:18:22 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/31 13:42:05 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_internal.h"

/*

Old ft_syscall.s:

-------------------------------------

.global __syscall
.type __syscall,%function
__syscall:
	movq %rdi,%rax
	movq %rsi,%rdi
	movq %rdx,%rsi
	movq %rcx,%rdx
	movq %r8,%r10
	movq %r9,%r8
	movq 8(%rsp),%r9
	syscall
	ret
.size __syscall,.-__syscall
.section .note.GNU-stack,"",@progbits

-------------------------------------

Removed because .s files are not allowed in submissions

So I remade a C implementation ¯\_(ツ)_/¯

*/

static __inline__ void	__get_args(va_list __arg_list, uint64_t __args[6])
{
	int32_t	i;

	i = -1;
	while (++i < 6)
		__args[i] = va_arg(__arg_list, uint64_t);
}

#if defined(__i386__)

__attribute__((__visibility__("hidden"))) \
	int32_t	__syscall(int32_t __flag, ...)
{
	va_list		arg_list;
	uint32_t	args[6];
	int32_t		result;

	va_start(arg_list, __flag);
	__get_args(arg_list, args);
	va_end(arg_list);
	__asm__(
		"movl %1, %%eax\n\t"
		"movl %2, %%ebx\n\t"
		"movl %3, %%ecx\n\t"
		"movl %4, %%edx\n\t"
		"movl %5, %%esi\n\t"
		"movl %6, %%edi\n\t"
		"int $0x80\n\t"
		"movl %%eax, %0\n\t"
		: "=r"(result)
		: "r"(__flag),
		"r"(args[0]), "r"(args[1]),
		"r"(args[2]), "r"(args[3]),
		"r"(args[4])
		: "eax", "ebx", "ecx", "edx", "esi", "edi"
		);
	return (result);
}

#elif defined(__x86_64__)

__attribute__((__visibility__("hidden"))) \
	int64_t	__syscall(int64_t __flag, ...)
{
	va_list		arg_list;
	uint64_t	args[6];
	uint64_t	result;

	va_start(arg_list, __flag);
	__get_args(arg_list, args);
	va_end(arg_list);
	__asm__(
		"movq %1, %%rax\n\t"
		"movq %2, %%rdi\n\t"
		"movq %3, %%rsi\n\t"
		"movq %4, %%rdx\n\t"
		"movq %5, %%r10\n\t"
		"movq %6, %%r8\n\t"
		"movq %7, %%r9\n\t"
		"syscall\n\t"
		"movq %%rax, %0\n\t"
		: "=r"(result)
		: "r"(__flag),
		"r"(args[0]), "r"(args[1]),
		"r"(args[2]), "r"(args[3]),
		"r"(args[4]), "r"(args[5])
		: "rax", "rdi", "rsi", "rdx", "r10", "r8", "r9"
		);
	return (result);
}

#elif defined(__arm__)

__attribute__((__visibility__("hidden"))) \
	int32_t	__syscall(int32_t __flag, ...)
{
	va_list		arg_list;
	uint32_t	args[6];
	int32_t		result;

	va_start(arg_list, __flag);
	__get_args(arg_list, args);
	va_end(arg_list);
	__asm__(
		"mov r0, %1\n\t"
		"mov r1, %2\n\t"
		"mov r2, %3\n\t"
		"mov r3, %4\n\t"
		"mov r4, %5\n\t"
		"mov r5, %6\n\t"
		"swi 0\n\t"
		"mov %0, r0\n\t"
		: "=r"(result)
		: "r"(__flag),
		"r"(args[0]), "r"(args[1]),
		"r"(args[2]), "r"(args[3]),
		"r"(args[4])
		: "r0", "r1", "r2", "r3", "r4", "r5"
		);
	return (result);
}

#elif defined(__aarch64__)

__attribute__((__visibility__("hidden"))) \
	int64_t	__syscall(int64_t __flag, ...)
{
	va_list		arg_list;
	uint64_t	args[6];
	uint64_t	result;

	va_start(arg_list, __flag);
	__get_args(arg_list, args);
	va_end(arg_list);
	__asm__(
		"mov x8, %1\n\t"
		"mov x0, %2\n\t"
		"mov x1, %3\n\t"
		"mov x2, %4\n\t"
		"mov x3, %5\n\t"
		"mov x4, %6\n\t"
		"mov x5, %7\n\t"
		"svc #0\n\t"
		"mov %0, x0\n\t"
		: "=r"(result)
		: "r"(__flag),
		"r"(args[0]), "r"(args[1]),
		"r"(args[2]), "r"(args[3]),
		"r"(args[4]), "r"(args[5])
		: "x0", "x1", "x2", "x3", "x4", "x5", "x8"
		);
	return (result);
}

#endif
