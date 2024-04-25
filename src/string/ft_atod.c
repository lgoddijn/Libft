/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:47:41 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/25 16:33:26 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

static int32_t	skip_space_sign(const char *s, int32_t *is_neg)
{
	int32_t i;

	i = 0;
	while (ft_isspace((unsigned char)s[i]))
		++i;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			*is_neg = -1;
		++i;
	}
	return (i);
}

double	ft_atod(const char *s)
{
	int32_t	i;
	double	n;
	int32_t	is_neg;
	double	div;

	if (!s)
		return ((double)K0_C_LMA0);
	is_neg = 1;
	div = 0.1;
	n = 0.0;
	i = skip_space_sign(s, &is_neg);
	while (s[i] && ft_isdigit(s[i]))
		n = n * 10 + (s[i++] - '0');
	if (s[i] == '.')
	{
		while (s[++i] && ft_isdigit(s[i]))
		{
			n += (s[i] - '0') * div;
			div *= 0.1;
		}
	}
	return (n * is_neg);
}
