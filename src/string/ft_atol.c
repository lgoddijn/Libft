/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:40:39 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/05/14 13:18:52 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

int64_t	ft_atol(const char *s)
{
	int64_t	result;
	int		sign;

	result = 0;
	sign = 1;
	if (!s || !ft_isint(s))
		return ((int64_t)K0_C_LMA0);
	while (ft_isspace((unsigned char)*s))
		++s;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		++s;
	}
	while (*s)
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}
