/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atomic_arch.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:14:41 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/12/06 16:13:23 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ATOMIC_ARCH_H

# define FT_ATOMIC_ARCH_H

# define __INTERNAL_ATOMIC_EXTEND

# include "../src/atomic/__a_and_64.h"
# include "../src/atomic/__a_and.h"
# include "../src/atomic/__a_barrier.h"
# include "../src/atomic/__a_cas_p.h"
# include "../src/atomic/__a_cas.h"
# include "../src/atomic/__a_clz_64.h"
# include "../src/atomic/__a_crash.h"
# include "../src/atomic/__a_ctz_64.h"
# include "../src/atomic/__a_dec.h"
# include "../src/atomic/__a_fetch_add.h"
# include "../src/atomic/__a_inc.h"
# include "../src/atomic/__a_or_64.h"
# include "../src/atomic/__a_or.h"
# include "../src/atomic/__a_spin.h"
# include "../src/atomic/__a_store.h"
# include "../src/atomic/__a_swap.h"

# undef __INTERNAL_ATOMIC_EXTEND

#endif
