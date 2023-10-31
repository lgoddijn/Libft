/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:53:35 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/31 16:32:22 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*

@def
	`ft_putendl_fd.c : ft_putendl_fd`

@brief
	Writes a string buffer + '\n' to a file.

@description
	Outputs the string ’s’ to the given file descriptor followed by a newline.

@synopsis
	`void	ft_putendl_fd(char *s, int fd);`

@params
	`char *s` The string buffer.
	`int fd` The file descriptor.

@return
	`void` Nothing.

@see
	`ft_putstr_fd.c : ft_putstr_fd`
	`ft_putchar_fd.c : ft_putchar_fd`

@extern
	`unistd.h : write(1)`

@notes
	This function must check if `s` is `NULL`
	since we dont want to just write an
	empty line in a file, since its
	accounted for as an extension of `s`

	All other possible errors are handled
	in the other functions used.

*/

void	ft_putendl_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
