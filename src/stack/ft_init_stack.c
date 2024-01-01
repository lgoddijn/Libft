/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:13:04 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:08:53 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_stack.h"

t_stack	*ft_init_stack(size_t max_size, size_t elem_size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = -1;
	stack->max_size = max_size;
	stack->elem_size = elem_size;
	stack->content = malloc(max_size * elem_size);
	if (!stack->content)
	{
		free(stack);
		return (NULL);
	}
	return (stack);
}
