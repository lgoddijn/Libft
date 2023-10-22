/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:17:49 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/18 18:11:02 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

@def
	`ft_lstsize_bonus.c : ft_lstsize`

@brief
	Counts the number of nodes in a linked list.

@description
	Counts the number of nodes in a list.

@synopsis
	`int	ft_lstsize(t_list *lst);`

@params
	`t_list *lst` The pointer to the first node of the linked list.

@returns
	`int` The number of nodes in the linked list.

@notes
	idk, just counting...

*/

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
