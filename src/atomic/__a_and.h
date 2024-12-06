/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __a_and.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:48:52 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/17 20:23:05 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __A_AND_H

# ifndef __INTERNAL_ATOMIC_EXTEND
#  error "Include `ft_atomic_arch.h` instead."
# endif

# define __A_AND_H

# define __A_AND	__a_and
# define _A_AND		__a_and
# define A_AND		__a_and

static __inline__ void	__a_and(volatile int *p, int v)
{
	__asm__	volatile (
			"lock ; and %1, %0"
			: "=m"(*p) : "r"(v) : "memory" );
}

extern __inline__ void	a_and(volatile int *p, int v)
						__attribute__((weak, alias("__a_and")));

#endif
