/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gethostname.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:12:23 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/01/01 20:36:48 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_unistd.h"

int	ft_gethostname(char *__name, size_t __len)
{
	size_t			i;
	struct utsname	uts;

	i = SIZE_MAX;
	if (uname(&uts))
		return (-1);
	if (__len > sizeof uts.nodename)
		__len = sizeof uts.nodename;
	while (++i < __len)
		__name[i] = uts.nodename[i];
	if (i == __len)
		__name[i - 1] = 0;
	return (0);
}
