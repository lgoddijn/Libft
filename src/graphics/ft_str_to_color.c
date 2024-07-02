/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:35:31 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/02 11:54:01 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_graphics.h"

t_color32	ft_str_to_color(const char *str)
{
	if (ft_isnull(str))
		return ((t_color32)0);
	return ((t_color32)ft_atox(str));
}
