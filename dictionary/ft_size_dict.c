/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_dict.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:55:02 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/11/19 17:56:19 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_size_dict(t_dict *dict)
{
	size_t	size;

	size = 0;
	while (dict && ++size)
		dict = dict->next;
	return (size);
}
