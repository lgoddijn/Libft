/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:40:58 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/19 23:48:27 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_file.h"

static void	handle_line(char **line, char **buf, size_t *buf_size, int32_t fd)
{
	size_t	line_size;

	line_size = ft_strlen(*line);
	*buf = (char *)ft_realloc(*buf, *buf_size + line_size + 1);
	if (!buf)
	{
		free(*line);
		ft_close(fd);
		ft_throw("Allocation Failure.");
	}
	ft_memcpy(*buf + *buf_size, *line, line_size);
	*buf_size += line_size;
	(*buf)[*buf_size] = '\0';
}

static void	read_lines(int32_t fd, char **buffer)
{
	int32_t		read_status;
	size_t		buffer_size;
	char		*line;

	line = NULL;
	buffer_size = 0;
	read_status = get_next_line(fd, &line);
	while (read_status > 0)
	{
		handle_line(&line, buffer, &buffer_size, fd);
		free(line);
		read_status = get_next_line(fd, &line);
	}
	if (read_status == 0 && line)
		handle_line(&line, buffer, &buffer_size, fd);
	if (read_status == -1 || (!*line && !read_status))
	{
		free(*buffer);
		ft_close(fd);
		ft_throw("Error while reading bytes from file.");
	}
	free(line);
}

char	*ft_read_file(const char *path)
{
	const int32_t	fd = ft_open(path, O_RDONLY);
	char			*buffer;

	if (fd == -1)
		ft_throw("Unable to open file: %s", path);
	buffer = NULL;
	read_lines(fd, &buffer);
	ft_close(fd);
	return (buffer);
}
