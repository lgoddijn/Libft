/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:02:19 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/11/03 20:09:32 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"

t_file	*get_file_state(int fd, t_file **head)
{
	t_file	*file_state;
	t_file	*tmp;

	tmp = *head;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	file_state = (t_file *)malloc(sizeof(t_file));
	if (!file_state)
		return (NULL);
	file_state->fd = fd;
	file_state->content = NULL;
	file_state->next = *head;
	*head = file_state;
	return (file_state);
}

int	update_content_buffer(char **content, char *buffer)
{
	char	*tmp;

	tmp = ft_strshove(*content, buffer);
	if (!tmp)
	{
		if (*content)
		{
			free(*content);
			*content = NULL;
		}
		return (0);
	}
	if (*content)
		free(*content);
	*content = tmp;
	return (1);
}
