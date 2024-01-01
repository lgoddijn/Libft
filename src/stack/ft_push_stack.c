/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:22:05 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/01/01 15:10:08 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_stack.h"

bool	ft_push_stack(t_stack *stack, void *elem)
{
	void	*target;

	if (!stack || ft_is_full_stack(stack))
		return (false);
	++(stack->top);
	target = (char *)stack->content + \
	(stack->top * stack->elem_size);
	ft_memcpy(target, elem, stack->elem_size);
	return (true);
}
