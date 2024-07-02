/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isanynull.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:55:48 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/02 11:03:10 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_memory.h"

bool	ft_isanynull(size_t count, ...)
{
	va_list	args;
	void	*arg;

	va_start(args, count);
	while (count--)
	{
		arg = va_arg(args, void *);
		if (arg == NULL)
		{
			va_end(args);
			return (true);
		}
	}
	va_end(args);
	return (false);
}
