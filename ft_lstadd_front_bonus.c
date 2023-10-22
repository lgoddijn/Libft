/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:15:37 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/22 16:25:49 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

@def
	`ft_lstadd_front_bonus.c : ft_lstadd_front`

@brief
	Adds a new node at the front of a linked list.

@description
	Adds the node ’new’ at the beginning of the list.

@synopsis
	`void	ft_lstadd_front(t_list **lst, t_list *new);`

@params
	`t_list **lst` The linked list to add the node to.
	`t_list *new`  The new node that should be appended.

@returns
	`void` Nothing.

@notes
	Check if both lst and new are valid
	otherwise a possible seg fault could occur

*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
