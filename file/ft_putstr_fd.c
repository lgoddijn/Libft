/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:48:09 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/31 16:32:29 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*

@def
	`ft_putstr_fd.c : ft_putstr_fd`

@brief
	Writes a string buffer to a file.

@description
	Outputs the string ’s’ to the given file descriptor.

@synopsis
	`void	ft_putstr_fd(char *s, int fd);`

@params
	`char *s` The string buffer to write.
	`int fd` The file descriptor.

@return
	`void` Nothing.

@see
	`ft_putchar_fd.c : ft_putchar_fd`

@extern
	`unistd.h : write(1)`

@notes
	`*s++` is the same as saying
	"first get the value of the ptr `s`,
	then increment the ptr `s`".

*/

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	while (*s)
		ft_putchar_fd(*s++, fd);
}
