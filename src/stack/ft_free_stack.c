/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:36:27 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:08:46 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_stack.h"

void	ft_free_stack(t_stack *stack, void (*del)(void *))
{
	if (stack && del)
	{
		del(stack->content);
		free(stack);
	}
}
