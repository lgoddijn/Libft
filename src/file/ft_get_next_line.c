/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:00:09 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/16 23:04:21 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_file.h"

static int32_t	ft_read_fd(int32_t fd, char **content)
{
	char	*buffer;
	ssize_t	bytes_read;
	int32_t	update_result;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	bytes_read = ft_read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		update_result = __update_content_buffer(content, buffer);
		if (!update_result || ft_strchr(buffer, '\n'))
		{
			free((void *)buffer);
			return (update_result);
		}
		bytes_read = ft_read(fd, buffer, BUFFER_SIZE);
	}
	free((void *)buffer);
	if (bytes_read <= 0)
		return (bytes_read);
	if (*content && **content)
		return (1);
	return (0);
}

static char	*extract_line(char **content, char *nl_pos)
{
	const char	*to_free = *content;
	char		*line;

	if (!nl_pos)
	{
		line = ft_strjoin(*content, NULL);
		if (!line)
			return (NULL);
		free((void *)*content);
		*content = NULL;
		return (line);
	}
	line = (char *)malloc(nl_pos - *content + 2);
	if (!line)
		return (NULL);
	ft_memcpy(line, *content, nl_pos - *content + 1);
	line[nl_pos - *content + 1] = '\0';
	if (*(nl_pos + 1) != '\0')
		*content = ft_strjoin(nl_pos + 1, NULL);
	else
		*content = NULL;
	free((void *)to_free);
	return (line);
}

static void	clear_entry(t_file **cache, t_file *entry)
{
	t_file	*previous_node;
	t_file	*current_node;

	previous_node = NULL;
	current_node = *cache;
	while (current_node)
	{
		if (current_node == entry)
		{
			if (previous_node)
				previous_node->next = current_node->next;
			else
				*cache = current_node->next;
			if (entry->content)
				free((void *)entry->content);
			free((void *)entry);
			break ;
		}
		previous_node = current_node;
		current_node = current_node->next;
	}
}

static bool	is_success(int read_status,
		t_file **cache, t_file *entry, char **line)
{
	if (read_status <= 0)
	{
		if (read_status < 0
			|| !entry->content
			|| !*entry->content)
			*line = NULL;
		else if (read_status == 0)
			*line = ft_strjoin(entry->content, NULL);
		clear_entry(cache, entry);
		return (false);
	}
	return (true);
}

int	get_next_line(int32_t fd, char **line)
{
	static t_file	*cache;
	t_file			*entry;
	int32_t			read_status;
	bool			success;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (-1);
	entry = __search_cache(fd, &cache);
	if (!entry)
		return (-1);
	while (!entry->content || !ft_strchr(entry->content, '\n'))
	{
		read_status = ft_read_fd(fd, &entry->content);
		success = is_success(read_status, &cache, entry, line);
		if (!success)
			return (read_status);
	}
	*line = extract_line(&entry->content,
			ft_strchr(entry->content, '\n'));
	if (!line || !*line || !entry->content || !*entry->content)
	{
		clear_entry(&cache, entry);
		return (0);
	}
	return (1);
}
