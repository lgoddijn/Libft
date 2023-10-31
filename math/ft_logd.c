/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:33:18 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/31 14:34:01 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

double	ft_logd(double x)
{
	int			n;
	double		result;
	double		term;
	const int	max_iter = 10;

	if (x <= 0)
		return (-1.0 / 0.0);
	n = 0;
	result = 0.0;
	term = x - 1.0;
	while (++n <= max_iter)
	{
		result += term / n;
		term *= -x + 1.0;
	}
	return (result);
}
