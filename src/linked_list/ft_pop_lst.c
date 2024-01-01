/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:30:21 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:06:10 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_linked_list.h"

/*

@def
	`ft_pop_lst.c : ft_pop_lst`

@brief
	Deletes a node.

@description
	Takes as a parameter a node and frees the memory of
	the node’s content using the function ’del’ given
	as a parameter and free the node. The memory of
	’next’ must not be freed.

@synopsis
	`void	ft_pop_lst(t_list *lst, void (*del)(void *));`

@params
	`t_list *lst` The node that should be deleted.
	`void (*del)(void *)` The function that deletes the content of the node.

@returns
	`void` Nothing.

@see
	`stdlib.h : free(3)`

@extern
	`stdlib.h : free(3)`

@notes
	The function should terminate if any argument is `NULL`
	The function does not need to check the return value
	of `del` since `del` returns `void`.

*/

void	ft_pop_lst(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
