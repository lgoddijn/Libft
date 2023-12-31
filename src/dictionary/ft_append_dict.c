/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_dict.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:49:18 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:03:11 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_dictionary.h"

void	ft_append_dict(t_dict **dict, t_dict *entry)
{
	t_dict	*last;

	if (dict && entry)
	{
		if (*dict == NULL)
			*dict = entry;
		else
		{
			last = ft_last_dict(*dict);
			last->next = entry;
		}
	}
}
