/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_dict.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:59:22 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/11/19 18:00:40 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_clear_dict(t_dict **dict, void (*del)(void*))
{
	t_dict	*next;

	if (!dict || !del)
		return ;
	while (*dict)
	{
		next = (*dict)->next;
		ft_del_one_dict(*dict, del);
		*dict = next;
	}
}
