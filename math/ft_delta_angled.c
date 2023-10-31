/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delta_angled.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 22:17:57 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/31 16:03:44 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

double	ft_delta_angled(double current, double target)
{
	double	num;

	num = target - current;
	while (num < 0)
		num += 360.0;
	while (num >= 360.0)
		num -= 360.0;
	if (num > 180.0)
		num -= 360.0;
	return (num);
}
