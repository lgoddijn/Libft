/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:48:53 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/08 19:58:54 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# ifndef __GNUC__
#  error "GNUC Required Due To Type Aliasing."
# endif

# if !defined(__x86_64__) || __SIZEOF_POINTER__ != 8
#  error "Only x86_64 Architecture Supported."
# endif

# if __BYTE_ORDER != __LITTLE_ENDIAN
#  error "Only Little Endian Byte Order Supported."
# endif

# include "ft_dirent.h"
# include "ft_env.h"
# include "ft_syscall.h"
# include "ft_memory.h"
# include "ft_string.h"
# include "ft_unistd.h"
# include "ft_values.h"
# include "ft_vector.h"

#endif
