/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:56:41 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/08/26 18:49:58 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

pid_t	ft_gettid(void)
{
	return ((pid_t)__syscall0(__NR_gettid));
}
