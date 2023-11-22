/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:11:37 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/11/19 19:15:11 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_digits(long n)
{
	size_t	digits;

	digits = 0;
	if (n <= 0)
		++digits;
	while (n != 0)
	{
		++digits;
		n /= 10;
	}
	return (digits);
}
