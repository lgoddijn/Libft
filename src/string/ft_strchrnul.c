/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrnul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:22:01 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/06/04 17:50:55 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

char	*ft_strchrnul(const char *s, int32_t c)
{
	const char	*ret = ft_strchr(s, c);

	if (ret)
		return ((char *)ret);
	return ((char *)s + ft_strlen(s));
}
