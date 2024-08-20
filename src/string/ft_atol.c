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
	int64_t	n;
	int32_t	neg;

	n = 0;
	neg = 0;
	while (ft_isspace(*s))
		++s;
	if (*s == '-')
		neg = 1;
	if (*s == '+')
		++s;
	while (ft_isdigit(*s))
		n = 10 * n - (*s++ - '0');
	if (neg)
		return (n);
	return (-n);
}
