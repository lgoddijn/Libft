/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __syscall6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:30:07 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/08/26 18:58:17 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_syscall.h"

long	__syscall6(long n, long a[6])
{
	const register long r10	__asm__("r10") = a[3];
	const register long r8	__asm__("r8") = a[4];
	const register long r9	__asm__("r9") = a[5];
	unsigned long			r;

	__asm__ (
		"syscall" : "=a"(r) : "a"(n), "D"(a[0]), "S"(a[1]), "d"(a[2]),
		"r"(r10), "r"(r8), "r"(r9) : "rcx", "r11", "memory");
	return ((long)r);
}
