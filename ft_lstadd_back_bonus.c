/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:24:00 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/22 16:25:46 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

@def
	`ft_lstadd_back_bonus.c : ft_lstadd_back`

@brief
	Adds a new node at the back of a linked list.

@description
	Adds the node ’new’ at the end of the list.

@synopsis
	`void	ft_lstadd_back(t_list **lst, t_list *new);`

@params
	`t_list **lst` The linked list to append the node to.
	`t_list *new`  The new node that should be appended.

@returns
	`void` Nothing.

@notes
	Check if both lst and new are valid
	otherwise a possible seg fault could occur

*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst && new)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			last = *lst;
			while (last->next != NULL)
				last = last->next;
			last->next = new;
		}
	}
}
