/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:21:50 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/12/31 18:02:25 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_print.h"

int	ft_print_ptr(const void *ptr_addr)
{
	if (ptr_addr == NULL)
		return (ft_print_str("(nil)"));
	if ((long)ptr_addr == LONG_MIN)
		return (ft_print_str("0x8000000000000000"));
	if ((long)ptr_addr == LONG_MAX)
		return (ft_print_str("0x7fffffffffffffff"));
	if ((unsigned long)ptr_addr == ULONG_MAX)
		return (ft_print_str("0xffffffffffffffff"));
	if ((unsigned long)ptr_addr == -ULONG_MAX)
		return (ft_print_str("0x1"));
	return (ft_print_hex((long long)ptr_addr, false, true));
}
