/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:22:10 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/01/01 15:01:38 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_math.h"

unsigned long long	ft_factorial(int n)
{
	unsigned long long	result;
	int					i;

	if (n < 0)
		return (0);
	result = 1;
	i = 1;
	while (i <= n)
		result *= ++i;
	return (result);
}
