/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:30:12 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/28 18:35:53 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

float	ft_logf(float x)
{
	int			n;
	float		result;
	float		term;
	const int	max_iter = 10;

	if (x <= 0)
		return (-1.0f / 0.0f);
	n = 0;
	result = 0.0f;
	term = x - 1.0f;
	while (++n <= max_iter)
	{
		result += term / n;
		term *= -x + 1.0f;
	}
	return (result);
}
