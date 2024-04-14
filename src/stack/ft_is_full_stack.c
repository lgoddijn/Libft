/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_full_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:19:36 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/14 18:27:02 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_stack.h"

bool	ft_is_full_stack(t_stack *stack)
{
	if (stack)
		return (stack->top == (int32_t)stack->max_size - 1);
	return (false);
}
