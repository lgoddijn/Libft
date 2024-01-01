/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:29:35 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 17:53:36 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H

# define FT_STACK_H

# include <stdlib.h>
# include <stdbool.h>

# include "ft_memory.h"

typedef struct s_stack
{
	int		top;
	size_t	max_size;
	size_t	elem_size;
	void	*content;
}	t_stack;

t_stack	*ft_init_stack(size_t max_size, size_t elem_size);
bool	ft_is_empty_stack(t_stack *stack);
bool	ft_is_full_stack(t_stack *stack);
bool	ft_peek_stack(t_stack *stack, void *out);
bool	ft_pop_stack(t_stack *stack, void *out);
bool	ft_push_stack(t_stack *stack, void *elem);
void	ft_free_stack(t_stack *stack, void (*del)(void *));

#endif