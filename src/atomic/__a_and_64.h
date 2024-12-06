/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __a_and_64.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:59:02 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/17 20:22:30 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __A_AND_64_H

# ifndef __INTERNAL_ATOMIC_EXTEND
#  error "Include `ft_atomic_arch.h` instead."
# endif

# define __A_AND_64_H

# include <stdint.h>

# define __A_AND_64	__a_and_64
# define _A_AND_64	__a_and_64
# define A_AND_64	__a_and_64

static __inline__ void	__a_and_64(volatile uint64_t *p, uint64_t v)
{
	__asm__	volatile (
			"lock ; and %1, %0"
			: "=m"(*p) : "r"(v) : "memory" );
}

extern __inline__ void	a_and_64(volatile uint64_t *p, uint64_t v)
						__attribute__((weak, alias("__a_and_64")));

#endif
