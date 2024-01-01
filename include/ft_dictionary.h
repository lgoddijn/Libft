/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictionary.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:28:54 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/01/01 14:43:23 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DICTIONARY_H

# define FT_DICTIONARY_H

# include "ft_string.h"

typedef struct s_dict
{
	void			*key;
	void			*value;
	struct s_dict	*next;
}	t_dict;

void	*ft_access_dict(t_dict *dict, const char *key);
t_dict	*ft_init_dict(void *key, void *value);
size_t	ft_size_dict(t_dict *dict);
t_dict	*ft_last_dict(t_dict *dict);
t_dict	*ft_search_dict(t_dict *dict, const char *key);
void	ft_prepend_dict(t_dict **dict, t_dict *entry);
void	ft_append_dict(t_dict **dict, t_dict *entry);
void	ft_pop_dict(t_dict *dict, void (*del)(void *));
void	ft_rm_entry_dict(t_dict *dict, const char *key, void (*del)(void *));
void	ft_clear_dict(t_dict **dict, void (*del)(void *));
void	ft_iter_dict(t_dict *dict, void (*f)(void *));
t_dict	*ft_map_dict(t_dict *dict, void *(*f)(void *), void (*del)(void *));

#endif