/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:19:55 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:06:03 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_linked_list.h"

/*

@def
	`ft_last_lst.c : ft_last_lst`

@brief
	Returns a pointer to the last node in a linked list.

@description
	Returns the last node of the list.

@synopsis
	`t_list	*ft_last_lst(t_list *lst);`

@params
	`t_list *lst` The starting node of the linked list.

@returns
	`t_list *` A pointer to the last node in the linked list.
	`NULL` if `*lst` is invalid. This is to prevent segfault.

@notes
	The function checks if `lst` is valid,
	this is because an invalid pointer
	(ex. `NULL` or kernel space)
	will automatically result in
	a seg fault or a bus error.

	The function loops witch the condition
	`lst->next` and not just `lst` because
	at the end of the list `lst` will segfault.

*/

t_list	*ft_last_lst(t_list *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		return (lst);
	}
	return (NULL);
}
