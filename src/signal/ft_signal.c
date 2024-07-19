/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 23:19:40 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/19 23:37:18 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_signal.h"

/* 
	Real definition:
		void	(*ft_signal(int __signo, void (*__f)(int32_t)))(int32_t)

	Norminette L as usual

	So instead of returning the function pointer
	its provided as an arg output.
*/

void	ft_signal(int32_t __signo, void (*__f)(int32_t), void (*__old)(int32_t))
{
	const struct sigaction	old = {.sa_handler = __f, .sa_flags = SA_RESTART};
	const struct sigaction	sa = {.sa_handler = __f, .sa_flags = SA_RESTART};

	if (sigaction(__signo, &sa, (struct sigaction *)&old) < 0)
		if (__old)
			__old = (void (*)(int32_t))SIG_ERR;
	if (__old)
		__old = old.sa_handler;
}
