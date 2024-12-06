/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __vm.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:50:58 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/12/06 16:13:01 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VM_H

# define __VM_H

# include "ft_atomic_arch.h"
# include "ft_syscall.h"
# include "ft_futex.h"

# include <limits.h>

# define __VM_LOCK_SIZE	2

static __always_inline volatile int	*__get_vmlock(void)
{
	static volatile int	vmlock[2];

	return (vmlock);
}

static __inline__ void	__wait(
		volatile int *addr,
		volatile int *waiters,
		int val, int priv)
{
	const long	futex_args[4] = {(long)addr, FUTEX_WAIT | priv, val, 0};
	int			spins;

	spins = 100;
	if (priv)
		priv = FUTEX_PRIVATE;
	while (spins-- && (!waiters || !*waiters))
	{
		if (*addr == val)
			a_spin();
		else
			return ;
	}
	if (waiters)
		a_inc(waiters);
	while (*addr == val)
	{
		if (__syscall4(__NR_futex, futex_args) != -ENOSYS)
			__syscall4(__NR_futex, (long [4]){(long)addr, FUTEX_WAIT, val, 0});
	}
	if (waiters)
		a_dec(waiters);
}

static __always_inline void	__vm_wait(void)
{
	volatile int	*vmlock;
	int				tmp;

	vmlock = __get_vmlock();
	tmp = vmlock[0];
	while (tmp)
	{
		__wait(vmlock, vmlock + 1, tmp, 1);
		tmp = vmlock[0];
	}
}

static __always_inline void	__vm_lock(void)
{
	a_inc(__get_vmlock());
}

static __always_inline void	__vm_unlock(void)
{
	volatile int	*vmlock;

	vmlock = __get_vmlock();
	if (a_fetch_add(vmlock, -1) == 1 && vmlock[1])
	{
		if (__syscall3(__NR_futex, (long)vmlock, FUTEX_WAKE \
			| FUTEX_PRIVATE, INT_MAX) != -ENOSYS)
			__syscall3(__NR_futex, (long)vmlock, FUTEX_WAKE, -1);
	}
}

#endif
