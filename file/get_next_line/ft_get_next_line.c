/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:00:09 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/05 16:09:35 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"

static int	ft_read_fd(int fd, char **content)
{
	char	*buffer;
	ssize_t	bytes_read;
	int		update_result;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		update_result = update_content_buffer(content, buffer);
		if (!update_result || ft_strchr(buffer, '\n'))
		{
			free(buffer);
			return (update_result);
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
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
		line = ft_strjoin(*content, NULL, false);
		if (!line)
			return (NULL);
		free(*content);
		*content = NULL;
		return (line);
	}
	line = (char *)malloc(nl_pos - *content + 2);
	if (!line)
		return (NULL);
	ft_memcpy(line, *content, nl_pos - *content + 1);
	line[nl_pos - *content + 1] = '\0';
	if (*(nl_pos + 1) != '\0')
		*content = ft_strjoin(nl_pos + 1, NULL, false);
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
				free(entry->content);
			free(entry);
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
			*line = ft_strjoin(entry->content, NULL, false);
		clear_entry(cache, entry);
		return (false);
	}
	return (true);
}

int	get_next_line(int fd, char **line)
{
	static t_file	*cache;
	t_file			*entry;
	int				read_status;
	bool			success;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (-1);
	entry = search_cache(fd, &cache);
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
