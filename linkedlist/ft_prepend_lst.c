/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepend_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:15:37 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/28 16:45:49 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*

@def
	`ft_prepend_lst.c : ft_prepend_lst`

@brief
	Adds a node node at the front of a linked list.

@description
	Adds the node ’node’ at the beginning of the list.

@synopsis
	`void	ft_prepend_lst(t_list **lst, t_list *node);`

@params
	`t_list **lst` The linked list to add the node to.
	`t_list *node`  The node node that should be appended.

@returns
	`void` Nothing.

@notes
	Check if both lst and node are valid
	otherwise a possible seg fault could occur

*/

void	ft_prepend_lst(t_list **lst, t_list *node)
{
	if (lst && node)
	{
		node->next = *lst;
		*lst = node;
	}
}
