/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rm_entry_dict.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:38:41 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:03:47 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_dictionary.h"

void	ft_rm_entry_dict(t_dict *dict, const char *key, void (*del)(void *))
{
	ft_pop_dict(ft_search_dict(dict, key), del);
}
