/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:47:41 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/14 18:27:42 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

static int32_t	skip_space_sign(const char *s, int32_t *is_neg)
{
	int32_t	i;

	i = 0;
	while (ft_isspace(s[i++]))
		;
	if ((s[i] == '+' || s[i] == '-') && s[i++] == '-')
		*is_neg *= -1;
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
	n = 0;
	div = 0.1;
	is_neg = 1;
	i = skip_space_sign(s, &is_neg);
	if (s[i] && !ft_isdigit(s[i]))
		return ((double)K0_C_LMA0);
	--i;
	while (s[++i] && ft_isdigit(s[i]) && s[i] != '.')
		n = (n * 10.0) + (s[i++] - '0');
	if (s[i] == '.')
		++i;
	while (s[i] && ft_isdigit(s[i]))
	{
		n = n + ((s[i] - '0') * div);
		div *= 0.1;
		++i;
	}
	return (n * is_neg);
}
