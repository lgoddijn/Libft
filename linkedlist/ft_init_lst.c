/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:06:52 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/28 16:45:41 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*

@def
	`ft_init_lst.c : ft_init_lst`

@brief
	Creates a new linked list pointer.

@description
	Allocates (with ft_calloc) and returns a new node.
	The member variable ’content’ is initialized with
	the value of the parameter ’content’. The variable
	’next’ is initialized to NULL.

@synopsis
	`t_list	*ft_init_lst(void *content);`

@params
	`void *content` The content pointer for the node.

@returns
	`t_list *` A pointer to the new node.
	`NULL` if the allocation for the new node fails.

@see
	`ft_calloc.c : ft_calloc`

@extern
	`stdlib.h : malloc(3)`

@notes
	Each node will be allocated as `1 * sizeof(t_list)`
	This is because each entry is an instance of `t_list`
	So remember that `t_list` is the node type.

	The `t_list.next` attribute should always be initialized to `NULL`,
	Redefining this will result in unwanted behavior in other functions.

	The `t_list.next` attribute does not need to be set to `NULL` since
	`ft_calloc` already sets all area in the memory allocation to `0` which
	when casting back to `void *` the literal value will be `NULL`.

*/

t_list	*ft_init_lst(void *content)
{
	t_list	*node;

	node = (t_list *)ft_calloc(
			1, sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = content;
	return (node);
}
