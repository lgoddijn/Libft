/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:30:09 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/01/01 15:09:41 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_stack.h"

bool	ft_pop_stack(t_stack *stack, void *out)
{
	if (!stack || ft_is_empty_stack(stack))
		return (false);
	ft_memcpy(out, (char *)stack->content + \
	(stack->top * stack->elem_size), \
	stack->elem_size);
	--(stack->top);
	return (true);
}
