/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:22:10 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/28 18:49:50 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

unsigned long long	ft_factorial(int n)
{
	unsigned long long	result;
	int					i;

	if (n < 0)
		return (NAN);
	result = 1;
	i = 1;
	while (i <= n)
		result *= ++i;
	return (result);
}
