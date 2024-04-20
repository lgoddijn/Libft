/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:49:34 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/20 17:31:38 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

static int32_t	skip_space_sign(const char *s, int32_t *is_neg)
{
	int32_t	i;

	i = 0;
	while (ft_isspace(s[i++]))
		;
	if (s[i] == '0' && (s[i + 1] && (s[i + 1] == 'x' || s[i] == 'X')))
		i += 2;
	if ((s[i] == '+' || s[i] == '-') && s[i++] == '-')
		*is_neg *= -1;
	return (i);
}

uint32_t	ft_atox(const char *s)
{
	uint32_t	result;
	int32_t		is_neg;
	int32_t		i;

	result = 0;
	i = skip_space_sign(s, &is_neg) - 1;
	if (!s[i + 1] || !ft_isdigit(s[i + 1]))
		return ((uint32_t)K0_C_LMA0);
	while (s[++i] != '\0')
	{
		if (*s >= '0' && *s <= '9')
			result = result * 16 + (*s - '0');
		if (*s >= 'a' && *s <= 'f')
			result = result * 16 + (*s - 'a' + 10);
		if (*s >= 'A' && *s <= 'F')
			result = result * 16 + (*s - 'A' + 10);
	}
	return (result);
}
