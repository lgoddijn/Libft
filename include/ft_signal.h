/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 22:07:22 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/19 23:42:19 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIGNAL_H

# define FT_SIGNAL_H

# include "ft_internal.h"
# include "ft_values.h"
# include "ft_unistd.h"

# include <signal.h>

// Yes somehow norminette agrees with this

__attribute__((__visibility__("hidden"))) __inline__ void \
	__block_all_sigs(void *__restrict__ __set)
{
	static const unsigned long	all_mask[] = {
		#if ULONG_MAX == 0xffffffff && _NSIG > 65
		-1UL, -1UL, -1UL, -1UL
		#elif ULONG_MAX == 0xffffffff || _NSIG > 65
		-1UL, -1UL
		#else
		-1UL
		#endif
	};

	if (!__x86_64__)
		return ;
	__syscall(__NR_rt_sigprocmask, SIG_BLOCK, &all_mask, __set, _NSIG / 8);
}

__attribute__((__visibility__("hidden"))) __inline__ void \
	__block_app_sigs(void *__restrict__ __set)
{
	static const unsigned long	app_mask[] = {
		#if ULONG_MAX == 0xffffffff
		#if _NSIG == 65
		0x7fffffff, 0xfffffffc
		#else
		0x7fffffff, 0xfffffffc, -1UL, -1UL
		#endif
		#else
		#if _NSIG == 65
		0xfffffffc7fffffff
		#else
		0xfffffffc7fffffff, -1UL
		#endif
		#endif
	};

	if (!__x86_64__)
		return ;
	__syscall(__NR_rt_sigprocmask, SIG_BLOCK, &app_mask, __set, _NSIG / 8);
}

__attribute__((__visibility__("hidden"))) __inline__ void \
	__restore_sigs(void *__restrict__ __set)
{
	if (!__x86_64__)
		return ;
	__syscall(__NR_rt_sigprocmask, SIG_SETMASK, __set, 0, _NSIG / 8);
}

int32_t			ft_raise(int32_t __signo);
int32_t			ft_kill(pid_t __pid, int32_t __sig);
void			ft_signal(
		int32_t __signo,
		void (*__f)(int32_t),
		void (*__old)(int32_t));
_Noreturn void	ft_abort(void);

#endif
