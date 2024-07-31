/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:48:53 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/31 14:08:23 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

@make
	All functions will now compile under the `all` rule.
	Since theres no more bonus' to comply to.

	Ex.
		`make fclean all`

@notes
	For documentation go to the respective `*.c` file
	Each function has its own `*.c` file named after it.
	(Given that I'm not too lazy to write it).

	Prototypes are split by usage cases.

	New functions will be added as time goes on.

	All new typedefs will be stored in this header file.

	All constants will be defined as macro definitions
	(ex. #define KEPSILON 1E-05f).

	The bonus functions were renamed to be more semantic.
	You can find them in the linked list sub-directory.

*/

#ifndef LIBFT_H

# define LIBFT_H

# include "ft_env.h"
# include "ft_file.h"
# include "ft_heap.h"
# include "ft_internal.h"
# include "ft_memory.h"
# include "ft_signal.h"
# include "ft_string.h"
# include "ft_unistd.h"
# include "ft_values.h"
# include "ft_vector.h"

#endif
