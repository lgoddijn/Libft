/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 22:03:35 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/19 23:38:29 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_signal.h"

_Noreturn void	ft_abort(void)
{
	const long				__signo = 1UL << (SIGABRT - 1);
	const float				__nsig = _NSIG / 8;
	pid_t					__tid;
	struct sigaction		__sa;

	__sa.sa_handler = SIG_DFL;
	ft_raise(SIGABRT);
	__block_all_sigs(0);
	__tid = __syscall(__NR_gettid);
	__syscall(SYS_rt_sigaction, SIGABRT, &__sa, 0, __nsig);
	__syscall(SYS_tkill, __tid, SIGABRT);
	__syscall(SYS_rt_sigprocmask, SIG_UNBLOCK,
		&(long [_NSIG / (8 * sizeof(long))]){__signo}, 0, __nsig);
	ft_raise(SIGKILL);
	ft_exit(127);
}
