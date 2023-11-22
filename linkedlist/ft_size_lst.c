/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:17:49 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/11/19 17:56:44 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*

@def
	`ft_size_lst.c : ft_size_lst`

@brief
	Counts the number of nodes in a linked list.

@description
	Counts the number of nodes in a list.

@synopsis
	`size_t	ft_size_lst(t_list *lst);`

@params
	`t_list *lst` The pointer to the first node of the linked list.

@returns
	`size_t` The number of nodes in the linked list.

@notes
	idk, just counting...

*/

size_t	ft_size_lst(t_list *lst)
{
	size_t	size;

	size = 0;
	while (lst && ++size)
		lst = lst->next;
	return (size);
}
