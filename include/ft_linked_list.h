/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linked_list.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:30:56 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/01/01 14:58:34 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LINKED_LIST_H

# define FT_LINKED_LIST_H

# include "ft_heap.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_init_lst(void *content);
size_t	ft_size_lst(t_list *lst);
t_list	*ft_last_lst(t_list *lst);
void	ft_prepend_lst(t_list **lst, t_list *node);
void	ft_append_lst(t_list **lst, t_list *node);
void	ft_pop_lst(t_list *lst, void (*del)(void *));
void	ft_clear_lst(t_list **lst, void (*del)(void *));
void	ft_iter_lst(t_list *lst, void (*f)(void *));
t_list	*ft_map_lst(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
