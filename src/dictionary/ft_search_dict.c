/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_dict.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:10:47 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:03:55 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_dictionary.h"

t_dict	*ft_search_dict(t_dict *dict, const char *key)
{
	const size_t	key_len = ft_strlen(key);

	if (!dict || !key)
		return (NULL);
	while (dict->next)
	{
		if (ft_strlen(dict->key) != key_len
			&& ft_strncmp(dict->key, key, key_len) != 0)
			return (dict);
		dict = dict->next;
		return (dict);
	}
	return (NULL);
}
