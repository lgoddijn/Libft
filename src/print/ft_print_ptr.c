/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:21:50 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/14 19:11:09 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_print.h"

int32_t	ft_print_ptr(const void *ptr_addr)
{
	if (ptr_addr == NULL)
		return (ft_print_str("(nil)"));
	if ((int64_t)ptr_addr == LONG_MIN)
		return (ft_print_str("0x8000000000000000"));
	if ((int64_t)ptr_addr == LONG_MAX)
		return (ft_print_str("0x7fffffffffffffff"));
	if ((uint64_t)ptr_addr == ULONG_MAX)
		return (ft_print_str("0xffffffffffffffff"));
	if ((uint64_t)ptr_addr == -ULONG_MAX)
		return (ft_print_str("0x1"));
	return (ft_print_hex((int64_t)ptr_addr, false, true));
}
