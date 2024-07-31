/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raise.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 22:10:30 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/31 13:42:24 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_signal.h"

int32_t	ft_raise(int32_t __signo)
{
	pid_t		tid;
	sigset_t	set;
	int32_t		ret;

	__block_app_sigs(&set);
	tid = __syscall(__NR_gettid);
	if (tid == -1)
		return (-1);
	ret = ft_kill(tid, __signo);
	__restore_sigs(&set);
	return (ret);
}
