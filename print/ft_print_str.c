/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:22:04 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/11/19 16:10:31 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_str(const char *buffer)
{
	int	c;

	c = 0;
	if (!buffer)
		return ((int)write(1, "(null)", 6));
	while (*buffer && ++c)
		ft_print_char(*buffer++);
	return (c);
}
