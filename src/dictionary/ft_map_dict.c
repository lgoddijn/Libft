/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_dict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:09:31 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:03:34 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_dictionary.h"

t_dict	*ft_map_dict(t_dict *dict, void *(*f)(void *), void (*del)(void *))
{
	t_dict	*new_dict;
	t_dict	*new_entry;
	void	*result;

	if (!dict || !f || !del)
		return (NULL);
	new_dict = NULL;
	while (dict)
	{
		result = f(dict->value);
		if (!result)
		{
			ft_clear_dict(&new_dict, del);
			return (NULL);
		}
		new_entry = ft_init_dict(dict->key, result);
		if (!new_entry)
		{
			ft_clear_dict(&new_dict, del);
			return (NULL);
		}
		ft_append_dict(&new_dict, new_entry);
		dict = dict->next;
	}
	return (new_dict);
}
