/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iter_dict.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:10:46 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/11/19 18:11:31 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_iter_dict(t_dict *dict, void (*f)(void *))
{
	if (!f)
		return ;
	while (dict)
	{
		f(dict->value);
		dict = dict->next;
	}
}
