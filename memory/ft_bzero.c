/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:49:28 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/31 16:27:07 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*

@def
	`ft_bzero.c : ft_bzero`

@brief
	Sets each value in a buffer to 0 up to `n`.

@man
    The  bzero()  function  erases  the  data  in the n bytes of the memory
    starting at the location pointed to by s, by writing zeros (bytes  con‐
    taining '\0') to that area.

@synopsis
	`void	ft_bzero(void *s, size_t n);`

@params
	`void *s`  The pointer to the buffer that needs to be set.
	`size_t n` The amount of elements to be set.

@returns
	`void` Nothing.

@see
	`ft_memset.c : ft_memset`

@notes
	`bzero` stands for "byte zero".
	Therefore it sets all elements to `\0`
	Here we use `0` because it is the
	ascii index of `\0` (byte zero).

	We don't need to check if
	`n` is 0 since memset
	will not affect `s`
	when `n` is 0.

*/

void	ft_bzero(void *s, size_t n)
{
	if (!s)
		return ;
	ft_memset(s, 0, n);
}
