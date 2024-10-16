/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alphasort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 00:33:53 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/10/16 00:36:57 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_dirent.h"

int	ft_alphasort(const struct dirent **a, const struct dirent **b)
{
	const size_t	a_len = ft_strlen((*a)->d_name);
	const size_t	b_len = ft_strlen((*b)->d_name);
	size_t			n;

	if (a_len > b_len)
		n = a_len;
	else
		n = b_len;
	return (ft_strncmp((*a)->d_name, (*b)->d_name, n));
}
