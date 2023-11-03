/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:00:09 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/11/03 20:07:12 by lgoddijn         ###   ########.fr       */
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
		line = ft_strshove(*content, NULL);
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
		*content = ft_strshove(nl_pos + 1, NULL);
	else
		*content = NULL;
	free((void *)to_free);
	return (line);
}

static void	remove_and_free_file(t_file **files, t_file *file)
{
	t_file	*previous_node;
	t_file	*current_node;

	previous_node = NULL;
	current_node = *files;
	while (current_node)
	{
		if (current_node == file)
		{
			if (previous_node)
				previous_node->next = current_node->next;
			else
				*files = current_node->next;
			if (file->content)
				free(file->content);
			free(file);
			break ;
		}
		previous_node = current_node;
		current_node = current_node->next;
	}
}

static bool	is_success(int read_status,
		t_file **files, t_file *state, char **line)
{
	if (read_status <= 0)
	{
		if (read_status < 0 || !state->content || !*state->content)
			*line = NULL;
		else if (read_status == 0)
			*line = ft_strshove(state->content, NULL);
		remove_and_free_file(files, state);
		return (false);
	}
	return (true);
}

char	*get_next_line(int fd)
{
	static t_file	*files;
	t_file			*state;
	char			*line;
	int				read_status;
	bool			success;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	state = get_file_state(fd, &files);
	if (!state)
		return (NULL);
	while (!state->content || !ft_strchr(state->content, '\n'))
	{
		read_status = ft_read_fd(fd, &state->content);
		success = is_success(read_status, &files, state, &line);
		if (!success)
			return (line);
	}
	line = extract_line(&state->content, ft_strchr(state->content, '\n'));
	if (!line || !state->content || !*state->content)
		remove_and_free_file(&files, state);
	return (line);
}
