/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:55:05 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/18 18:10:32 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

@def
	`ft_putnbr_fd.c : ft_putnbr_fd`

@brief
	Writes an integer to a file.

@description
	Outputs the integer ’n’ to the given file descriptor.

@synopsis
	`void	ft_putnbr_fd(int n, int fd);`

@params
	`int n` The number to write.
	`int fd` The file descriptor.

@return
	`void` Nothing.

@see
	`unistd.h : write(1)`

@extern
	`unistd.h : write(1)`

@notes
	Since the `ft_itoa` function uses `malloc(3)`.
	We have to do make the function from scratch.
	This is because `malloc(3)` is not allowed
	and we would also need to use `free(3)`

	The same edge cases as `ft_itoa` are handled.

	The function uses recursion, its best not to
	use it for safety and efficiency however
	for the sake of conciseness I used it.

*/

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == INT_MIN)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}
