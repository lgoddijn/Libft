/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alarm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 15:49:12 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/31 13:24:23 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

uint32_t	ft_alarm(uint32_t seconds)
{
	return ((uint32_t)__syscall(__NR_alarm, seconds));
}
