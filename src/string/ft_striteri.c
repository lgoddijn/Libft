/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:41:27 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:10:56 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

/*

@def
	`ft_striteri.c : ft_striteri`

@brief
	Applies the function `f` to every character in a string buffer.

@description
    Applies the function ’f’ on each character of
	the string passed as argument, passing its index
	as first argument. Each character is passed by
	address to ’f’ to be modified if necessary.

@synopsis
	`void	ft_striteri(char *s, void (*f)(unsigned int, char*));`

@params
	`char *s` The string buffer to modify using `f`.
	`void (*f)(unsigned int, char*)` The function to apply.

@return
	`void` Nothing.

@notes
	Should check by design the arguments
	to avoid seg faults.

	Pointer arithmentics are used
	instead of indexing as it might
	be slightly more efficient on
	certain computer systems.

	(L Milan, I can justify it.)

*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	char	*ptr;

	if (!s || !f)
		return ;
	ptr = s - 1;
	while (*++ptr)
		f(ptr - s, ptr);
}
