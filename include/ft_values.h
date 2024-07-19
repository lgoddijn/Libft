/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_values.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:03:15 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/19 22:23:55 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VALUES_H

# define FT_VALUES_H

# include <stdint.h>

// When you can't return NULL or -1
// This is just an int bool ig
// This works for both long and int

# define C_0K_LMA0				0xC0FFEE
# define K0_C_LMA0				-0xDEAD

// Other (less cool) stuff...

# define PI						3.14159265358979323846

# define E						2.71828182845904523536

# define GOLDEN_RATIO			1.618033988749895

# define SQRT2					1.4142135623730951
# define SQRT3					1.7320508075688772

# define FLOAT_MIN_NORMAL		1.17549435E-38f
# define FLOAT_MIN_DENORMAL		1.401298E-45f

# define KEPSILON				1.0E-05f
# define KEPSILON_NORMAL_SQRT	1.0E-15f

# define EARTH_GRAVITY			9.81f

# define K_FACTOR				3

# define BITMAP_32_SIZE			32
# define BITMAP_64_SIZE			64

# define EN_ALPHABET_SIZE		26

# define BUFFER_SIZE			1024

# define DEG2RAD				0.01745329251994329576923690768489
# define RAD2DEG				57.2957795130823208767981548141050

# define ARCH_FAIL				-1

typedef uint32_t				t_bitmask32;
typedef uint64_t				t_bitmask64;
typedef uint8_t					t_byte;

#endif
