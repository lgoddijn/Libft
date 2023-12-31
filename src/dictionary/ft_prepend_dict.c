/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepend_dict.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:51:35 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:03:44 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_dictionary.h"

void	ft_prepend_dict(t_dict **dict, t_dict *entry)
{
	if (dict && entry)
	{
		entry->next = *dict;
		*dict = entry;
	}
}
