/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:22:05 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/11/25 16:46:10 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

bool	ft_push_stack(t_stack *stack, void *elem)
{
	void	*target;

	if (!stack || ft_is_full_stack(stack))
		return (false);
	++(stack->top);
	target = stack->content + \
	(stack->top * stack->elem_size);
	ft_memcpy(target, elem, stack->elem_size);
	return (true);
}
