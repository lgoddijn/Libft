/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:45:16 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/25 17:59:41 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

@def
	`ft_lstiter_bonus.c : ft_lstiter`

@brief
	Applies a function to the content of each node of a linked list.

@description
	Iterates the list ’lst’ and applies the function
	’f’ on the content of each node.

@synopsis
	`void	ft_lstiter(t_list *lst, void (*f)(void *));`

@params
	`t_list *lst` 		  The starting node of the linked list.
	`void (*f)(void *)`   The function to apply to each of the nodes' content.

@returns
	`void` Nothing.

@notes
	The function does not need to check the return
	of `f` since the function returns `void`.

*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
