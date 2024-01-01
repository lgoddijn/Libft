/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gaussian_kerneld.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 22:00:54 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:26:27 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_math.h"

double	ft_gaussian_kerneld(double d, double sigma)
{
	return (ft_expd(-ft_powd(d, 2) / (2 * ft_powd(sigma, 2))));
}
