/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:47:02 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/31 16:32:18 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*

@def
	`ft_putchar_fd.c : ft_putchar_fd`

@brief
	Writes a character to a file.

@description
	Outputs the character ’c’ to the given file descriptor.

@synopsis
	`void	ft_putchar_fd(char c, int fd);`

@params
	`char c` The character to write.
	`int fd` The file descriptor.

@return
	`void` Nothing.

@see
	`unistd.h : write(1)`

@extern
	`unistd.h : write(1)`

@notes
	I'm using `sizeof(char)` instead of `1`
	incase the size of `char` will change.

	Nah I'm just kidding, it looks cooler.

	Also note that if `fd` is invalid
	the write function will note crash.

*/

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, sizeof(char));
}
