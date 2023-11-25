/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rm_entry_dict.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:38:41 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/11/25 16:42:54 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_rm_entry_dict(t_dict *dict, const char *key, void (*del)(void *))
{
	ft_pop_dict(ft_search_dict(dict, key), del);
}
