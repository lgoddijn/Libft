/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:30:21 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/25 18:00:15 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

@def
	`ft_lstdelone_bonus.c : ft_lstdelone`

@brief
	Deletes a node.

@description
	Takes as a parameter a node and frees the memory of
	the node’s content using the function ’del’ given
	as a parameter and free the node. The memory of
	’next’ must not be freed.

@synopsis
	`void	ft_lstdelone(t_list *lst, void (*del)(void*));`

@params
	`t_list *lst` The node that should be deleted.
	`void (*del)(void*)` The function that deletes the content of the node.

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

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}
