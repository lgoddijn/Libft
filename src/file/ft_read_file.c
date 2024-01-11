/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:40:58 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/01/11 16:37:10 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_file.h"

static void	handle_line(char **line, char **buffer, size_t *buffer_size, int fd)
{
	size_t	line_size;

	line_size = ft_strlen(*line);
	*buffer = (char *)ft_realloc(*buffer, *buffer_size + line_size + 1);
	if (!buffer)
	{
		free(*line);
		ft_close(fd);
		ft_raise("Allocation Failure.");
	}
	ft_memcpy(*buffer + *buffer_size, *line, line_size);
	*buffer_size += line_size;
	(*buffer)[*buffer_size] = '\0';
}

static void	read_lines(int fd, char **buffer)
{
	int			read_status;
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
		ft_raise("Error while reading bytes from file.");
	}
	free(line);
}

char	*ft_read_file(const char *path)
{
	const int	fd = ft_open(path, O_RDONLY);
	char		*buffer;

	if (fd == -1)
		ft_raise("Unable to open file: %s", path);
	buffer = NULL;
	read_lines(fd, &buffer);
	ft_close(fd);
	return (buffer);
}
