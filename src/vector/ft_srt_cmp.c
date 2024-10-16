/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srt_cmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 01:36:15 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/10/16 01:36:48 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_vector.h"

void	ft_srt_cmp(
		void *b, size_t nel, size_t w,
		int (*cmp)(const void *, const void *))
{
	return (qsort(b, nel, w, cmp));
}
