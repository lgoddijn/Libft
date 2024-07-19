/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memequals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 20:20:32 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/18 20:23:55 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_memory.h"

bool	ft_memequals(const void *lhs, const void *rhs)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	if (lhs == rhs)
		return (true);
	if (!lhs || !rhs)
		return (false);
	ptr1 = (unsigned char *)lhs;
	ptr2 = (unsigned char *)rhs;
	while (*ptr1 && *ptr2)
		if (*ptr1++ != *ptr2++)
			return (false);
	if (*ptr1 == *ptr2)
		return (true);
	return (false);
}
