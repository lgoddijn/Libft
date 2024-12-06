/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __a_swap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:30:31 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/17 20:21:34 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __A_SWAP_H

# ifndef __INTERNAL_ATOMIC_EXTEND
#  error "Include `ft_atomic_arch.h` instead."
# endif

# define __A_SWAP_H

# define __A_SWAP	__a_swap
# define _A_SWAP	__a_swap
# define A_SWAP		__a_swap

static __inline__ int	__a_swap(volatile int *p, int v)
{
	__asm__	volatile (
			"xchg %0, %1"
			: "=r"(v), "=m"(*p) : "0"(v) : "memory" );

	return (v);
}

extern __inline__ int	a_swap(volatile int *p, int v)
						__attribute__((weak, alias("__a_swap")));

#endif
