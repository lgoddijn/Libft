/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 17:04:23 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/01/11 15:39:56 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H

# define FT_PRINT_H

# include <stddef.h>

# include "ft_string.h"
# include "ft_unistd.h"

int		ft_print_char(const int c);
int		ft_print_str(const char *buffer);
int		ft_print_int(int n);
int		ft_print_uint(const unsigned int n);
int		ft_print_hex(long long n, const bool is_upper, const bool is_ptr);
int		ft_print_ptr(const void *ptr_addr);
int		ft_printf(const char *fmt, ...);
void	ft_raise(const char *msg, ...);

#endif
