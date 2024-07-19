/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 17:04:23 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/19 23:47:48 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H

# define FT_PRINT_H

# include <stddef.h>

# include "ft_string.h"
# include "ft_unistd.h"

int32_t	ft_print_char(const int32_t c);
int32_t	ft_print_str(const char *buffer);
int32_t	ft_print_int(int32_t n);
int32_t	ft_print_uint(const uint32_t n);
int32_t	ft_print_hex(int64_t n, const bool is_upper, const bool is_ptr);
int32_t	ft_print_ptr(const void *ptr_addr);
int32_t	ft_printf(const char *fmt, ...);
void	ft_throw(const char *msg, ...);

#endif
