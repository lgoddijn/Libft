/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:03:10 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/14 19:15:37 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_H

# define FT_FILE_H

# include <fcntl.h>
# include <unistd.h>

# include "ft_internal.h"
# include "ft_string.h"
# include "ft_print.h"

typedef struct s_file
{
	int32_t			fd;
	char			*content;
	struct s_file	*next;
}	t_file;

t_file	*__search_cache(int32_t fd, t_file **head);
int32_t	__update_content_buffer(char **content, char *buffer);

int32_t	get_next_line(int32_t fd, char **line);
char	*ft_read_file(const char *path);

#endif
