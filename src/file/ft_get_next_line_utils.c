/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:02:19 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/16 23:04:42 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_file.h"

t_file	*__search_cache(int32_t fd, t_file **cache)
{
	t_file	*entry;
	t_file	*tmp;

	tmp = *cache;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	entry = (t_file *)malloc(sizeof(t_file));
	if (!entry)
		return (NULL);
	entry->fd = fd;
	entry->content = NULL;
	entry->next = *cache;
	*cache = entry;
	return (entry);
}

int32_t	__update_content_buffer(char **content, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(*content, buffer);
	if (!tmp)
	{
		if (*content)
		{
			free((void *)*content);
			*content = NULL;
		}
		return (0);
	}
	if (*content)
		free((void *)*content);
	*content = tmp;
	return (1);
}
