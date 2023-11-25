/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:36:27 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/11/25 16:44:29 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_free_stack(t_stack *stack, void (*del)(t_stack *))
{
	if (stack && del)
	{
		del(stack->content);
		free(stack);
	}
}
