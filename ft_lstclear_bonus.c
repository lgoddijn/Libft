/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:34:03 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/25 18:00:25 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

@def
	`ft_lstclear_bonus.c : ft_lstclear`

@brief
	Clears a linked list.

@description
	Deletes and frees the given node and every
	successor of that node, using the function ’del’
	and free(3).
	Finally, the pointer to the list must be set to
	NULL.

@synopsis
	`void	ft_lstclear(t_list **lst, void (*del)(void*));`

@params
	`t_list **lst` The linked list to add the node to.
	`void (*del)(void*)` The function that deletes the content of each node.

@returns
	`void` Nothing.

@see
	`ft_lstdelone.c : ft_lstdelone`

@extern
	`stdlib.h : free(3)`

@notes
	If either argument is `NULL` the function should terminate.
	The `ft_lstdelone` function already calls the free and del
	function on the node and its content, therefore less is more.

	The function does not need to check the return value
	of `del` since `del` returns `void`.

*/

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next;
	}
}
