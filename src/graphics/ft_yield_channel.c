/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_yield_channel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:23:21 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/02 13:17:28 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_graphics.h"

t_channel	ft_yield_channel(t_channel *buf, size_t size)
{
	static int	index = 0;

	if (ft_isnull(buf))
		return ((t_channel)0);
	if (index > size)
		index = 0;
	return (buf[index++]);
}
