/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_one_dict.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:57:05 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/11/19 17:58:13 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_del_one_dict(t_dict *dict, void (*del)(void*))
{
	if (!dict || !del)
		return ;
	del(dict->value);
	free(dict);
}
