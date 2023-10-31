/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:52:59 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/28 16:45:47 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*

@def
	`ft_map_lst.c : ft_map_lst`

@brief
	Creates a new linked list applying the function `f` to the content.

@description
	Iterates the list ’lst’ and applies the function
	’f’ on the content of each node. Creates a new
	list resulting of the successive applications of
	the function ’f’. The ’del’ function is used to
	delete the content of a node if needed.

@synopsis
	`t_list	*ft_map_lst(t_list *lst, void *(*f)(void *), void (*del)(void *));`

@params
	`t_list *lst` The starting node of the linked list.
	`void *(*f)(void *)` The function to apply to the content of each node.
	`void (*del)(void *)` The function to delete the content of the old linked list.

@returns
	`t_list *` A pointer to the first node in the new linked list.
	`NULL` if either `*lst` `f` `del` are invalid.
	`NULL` if the allocation for any new node fails.

@see
	`ft_init_lst.c : ft_init_lst`
	`ft_clear_lst.c : ft_clear_lst`
	`ft_append_lst.c : ft_append_lst`

@extern
	`stdlib.h : malloc(3)`
	`stdlib.h : free(3)`

@notes
	The function is designed to return `NULL`
	if any argument is invalid, otherwise this
	could result in unwanted crashes and behavior.

	The function is designed to clear the new list
	and terminate if any of the new nodes fail to allocate.
	This is to avoid any data loss by the caller of this function.
	The function is also prone to memory leaks and unwanted behavior.

	The `ft_lstadd_back` is slightly inefficient.
	An `O(1)` approach might be better.

	We should also check if the result of `f` is `NULL`
	since `f` returns `void *` therefore the return value
	could infact be `NULL` unlike other argument functions
	which do not return `void *`.

*/

t_list	*ft_map_lst(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*result;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		result = f(lst->content);
		if (!result)
		{
			ft_clear_lst(&new_list, del);
			return (NULL);
		}
		new_node = ft_init_lst(result);
		if (!new_node)
		{
			ft_clear_lst(&new_list, del);
			return (NULL);
		}
		ft_append_lst(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
