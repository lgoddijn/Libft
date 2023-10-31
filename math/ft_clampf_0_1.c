/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clampf_0_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:38:43 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/28 17:17:02 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

float	ft_clampf_0_1(float value)
{
	if (value < 0.0f)
		return (0.0f);
	if (value > 1.0f)
		return (1.0f);
	return (value);
}
