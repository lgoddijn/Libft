/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:52:56 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/14 18:21:32 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_math.h"

int32_t	ft_mod(int32_t x, int32_t y)
{
	return ((x) - ((int32_t)((x) / (y))) * (y));
}
