/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:34:03 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:05:31 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_linked_list.h"

/*

@def
	`ft_clear_lst.c : ft_clear_lst`

@brief
	Clears a linked list.

@description
	Deletes and frees the given node and every
	successor of that node, using the function ’del’
	and free(3).
	Finally, the pointer to the list must be set to
	NULL.

@synopsis
	`void	ft_clear_lst(t_list **lst, void (*del)(void *));`

@params
	`t_list **lst` The linked list to add the node to.
	`void (*del)(void *)` The function that deletes the content of each node.

@returns
	`void` Nothing.

@see
	`ft_pop_lst.c : ft_pop_lst`

@extern
	`stdlib.h : free(3)`

@notes
	If either argument is `NULL` the function should terminate.
	The `ft_lstdelone` function already calls the free and del
	function on the node and its content, therefore less is more.

	The function does not need to check the return value
	of `del` since `del` returns `void`.

*/

void	ft_clear_lst(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		ft_pop_lst(*lst, del);
		*lst = next;
	}
}
