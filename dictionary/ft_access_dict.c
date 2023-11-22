/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access_dict.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:22:12 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/11/20 18:42:32 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_access_dict(t_dict *dict, const char *key)
{
	const t_dict	*entry = ft_search_dict(dict, key);

	if (!entry)
		return (NULL);
	return (entry->value);
}
