/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aggregate_v3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:12:38 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/28 16:21:37 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_vector3	ft_aggregate_v3(t_vector3 *vectors, size_t size, float t)
{
	t_vector3	result;
	t_vector3	interp;
	size_t		i;

	i = 0;
	result = ft_init_v3(0.0f, 0.0f, 0.0f);
	while (i++ < size - 1)
	{
		interp = ft_lerp_v3(vectors[i - 1], vectors[i], t);
		result = ft_add_v3(result, interp);
	}
	return (result);
}
