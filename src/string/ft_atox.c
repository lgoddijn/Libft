/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:49:34 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/05/14 13:21:05 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

static int32_t	skip_space_sign(const char *s, int32_t *is_neg)
{
	int32_t	i;

	i = 0;
	while (ft_isspace((int32_t)s[i++]))
		;
	if (s[i] == '0' && (s[i + 1] && (s[i + 1] == 'x' || s[i] == 'X')))
		i += 2;
	if ((s[i] == '+' || s[i] == '-') && s[i++] == '-')
		*is_neg *= -1;
	return (i);
}

int32_t	ft_atox(const char *s)
{
	int32_t	result;
	int32_t	is_neg;
	int32_t	i;

	result = 0;
	is_neg = 1;
	if (!s || !*s)
		return ((int32_t)K0_C_LMA0);
	i = skip_space_sign(s, &is_neg) - 1;
	if (!s[i + 1] || (!ft_isalnum(s[i + 1])))
		return ((int32_t)K0_C_LMA0);
	while (s[++i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
			result = result * 16 + (s[i] - '0');
		else if (s[i] >= 'a' && s[i] <= 'f')
			result = result * 16 + (s[i] - 'a' + 10);
		else if (s[i] >= 'A' && s[i] <= 'F')
			result = result * 16 + (s[i] - 'A' + 10);
	}
	return (result * is_neg);
}
