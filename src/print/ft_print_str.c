/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:22:04 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/14 18:24:22 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_print.h"

int32_t	ft_print_str(const char *buffer)
{
	if (!buffer)
		return ((int32_t)ft_write(1, "(null)", 6));
	return ((int32_t)ft_write(1, buffer, ft_strlen(buffer)));
}
