/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:49:09 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/08/26 18:48:58 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

char	*ft_getcwd(char *__buf, size_t __size)
{
	long	ret;

	ret = __syscall2(__NR_getcwd, (long)__buf, __size);
	if (ret < 0)
		return (NULL);
	if (ret == 0 || __buf[0] != '/')
		return (NULL);
	return (__buf);
}
