/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_futex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:09:18 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/12/06 16:12:41 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FUTEX_H

# define FT_FUTEX_H

# ifndef __NR_futex
#  define __NR_FUTEX	202
# endif

# define FUTEX_WAIT				0
# define FUTEX_WAKE				1
# define FUTEX_FD				2
# define FUTEX_REQUEUE			3
# define FUTEX_CMP_REQUEUE		4
# define FUTEX_WAKE_OP			5
# define FUTEX_LOCK_PI			6
# define FUTEX_UNLOCK_PI		7
# define FUTEX_TRYLOCK_PI		8
# define FUTEX_WAIT_BITSET		9
# define FUTEX_PRIVATE			128
# define FUTEX_CLOCK_REALTIME	256

#endif
