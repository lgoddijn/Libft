/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrtf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:15:04 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:29:29 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_math.h"

/*

@def
	`ft_sqrtf.c : ft_sqrtf`

@brief
	Calculates the square root of a float number.

@description
	Calculates the square root of a float
	number using the quake algorithm.

@synopsis
	`float	ft_sqrtf(float n);`

@params
	`float n` The number of which the sqrt is calculated.

@return
	`float` The square root of `n`

@see
	`libft.h : u_sqrtf`

@notes
	The function uses a union named `u_sqrtf`.
	A union allows one to store different data types
	in the same memory location. The union is used 
	to perform type punning, which allows us to manipulate
	the bitwise representation of a float as an integer.

    The function sets the float member of the union to the input value, `n`.

    `conv.i = 0x5fe6eb50c7b537a9 - (conv.i >> 1);`:
	This is the heart of the fast inverse square root method.
	The number `0x5fe6eb50c7b537a9` is a "magic" constant.
	By performing this operation on the integer representation of a float,
	we're making an initial approximation of the inverse square root.
	The bit-shifting operation `(>> 1)` roughly divides the exponent of
	the floating-point number by 2, which is an approximation of the square root.

	`conv.d *= (th - (x2 * conv.d * conv.d));`:
	This line refines the approximation. It uses the Newton-Raphson method,
	which is a numerical method to find successively better approximations
	to the roots of a real-valued function. Here, it's applied to refine
	our initial guess of the inverse square root.

	To have a more precise return use `math/ft_sqrtd.c : ft_sqrtd`.

	The function returns the square root of `n` by taking
	the inverse of our computed inverse square root.
*/

/*

CURRENTLY DOESN'T WORK

               D,:

*/

float	ft_sqrtf(float n)
{
	const float		x2 = n * 0.5;
	const float		th = 1.5;
	union u_sqrtf	conv;

	if (n < 0.0f)
		return (0.0f);
	conv.d = n;
	conv.i = 0x5fe6eb50c7b537a9 - (conv.i >> 1);
	conv.d *= (th - (x2 * conv.d * conv.d));
	return (1.0 / conv.d);
}
