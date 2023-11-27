/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:30:09 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/11/25 17:59:43 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

bool	ft_pop_stack(t_stack *stack, void *out)
{
	if (!stack || ft_is_empty_stack(stack))
		return (false);
	ft_memcpy(out, stack->content + \
	(stack->top * stack->elem_size, \
	stack->elem_size), stack->elem_size);
	--(stack->top);
	return (true);
}
