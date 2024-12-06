/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __a_store.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:16:07 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/17 20:27:08 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __A_STORE_H

# ifndef __INTERNAL_ATOMIC_EXTEND
#  error "Include `ft_atomic_arch.h` instead."
# endif

# define __A_STORE_H

# define __A_STORE	__a_store
# define _A_STORE	__a_store
# define A_STORE	__a_store

static __inline__ void	__a_store(volatile int *p, int x)
{
	__asm__	volatile (
			"mov %1, %0 ; lock ; orl $0,(%%rsp)"
			: "=m"(*p) : "r"(x) : "memory" );
}

extern __inline__ void	a_store(volatile int *p, int x)
						__attribute__((weak, alias("__a_store")));

#endif
