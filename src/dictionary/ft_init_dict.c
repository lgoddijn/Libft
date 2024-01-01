/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_dict.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:05:20 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:03:20 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_dictionary.h"

t_dict	*ft_init_dict(void *key, void *value)
{
	t_dict	*dict;

	dict = (t_dict *)ft_calloc(
			1, sizeof(t_dict));
	if (dict)
	{
		dict->key = key;
		dict->value = value;
	}
	return (dict);
}
