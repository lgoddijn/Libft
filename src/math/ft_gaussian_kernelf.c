/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gaussian_kernelf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 22:21:24 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:26:31 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_math.h"

float	ft_gaussian_kernelf(float d, float sigma)
{
	return (ft_expf(-ft_powf(d, 2) / (2 * ft_powf(sigma, 2))));
}
