/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:22:10 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/14 19:07:09 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_math.h"

uint64_t	ft_factorial(int32_t n)
{
	uint64_t	result;
	int32_t		i;

	if (n < 0)
		return (0);
	result = 1;
	i = 1;
	while (i <= n)
		result *= ++i;
	return (result);
}
