/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gaussian_kerneld.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 22:00:54 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/29 22:21:07 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

double	ft_gaussian_kerneld(double d, double sigma)
{
	return (ft_expd(-ft_powd(d, 2) / (2 * ft_powd(sigma, 2))));
}
