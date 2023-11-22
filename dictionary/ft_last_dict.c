/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_dict.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:54:02 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/11/19 17:54:37 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_dict	*ft_last_dict(t_dict *dict)
{
	if (dict)
	{
		while (dict->next)
			dict = dict->next;
		return (dict);
	}
	return (NULL);
}
