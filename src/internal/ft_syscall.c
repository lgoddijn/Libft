/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 18:18:22 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/05/16 17:31:03 by lgoddijn         ###   ########.fr       */
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

static void	__get_args(
	va_list __arg_list,
	uint64_t __args[6])
{
	int32_t	i;

	i = -1;
	while (++i < 6)
		__args[i] = va_arg(
				__arg_list,
				uint64_t);
}

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
