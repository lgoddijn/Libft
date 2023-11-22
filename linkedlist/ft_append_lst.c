/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:24:00 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/11/19 17:50:32 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*

@def
	`ft_append_lst.c : ft_append_lst`

@brief
	Adds a node node at the back of a linked list.

@description
	Adds the node ’node’ at the end of the list.

@synopsis
	`void	ft_append_lst(t_list **lst, t_list *node);`

@params
	`t_list **lst` The linked list to append the node to.
	`t_list *node`  The node node that should be appended.

@returns
	`void` Nothing.

@notes
	Check if both lst and node are valid
	otherwise a possible seg fault could occur

*/

void	ft_append_lst(t_list **lst, t_list *node)
{
	t_list	*last;

	if (lst && node)
	{
		if (*lst == NULL)
			*lst = node;
		else
		{
			last = ft_last_lst(*lst);
			last->next = node;
		}
	}
}
