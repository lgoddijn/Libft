/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:50:22 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/05/14 15:12:06 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

int32_t	ft_atoi(const char *s)
{
	int32_t	n;
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
