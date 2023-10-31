/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smooth_stepf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:52:25 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/31 14:42:50 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

float	ft_smooth_stepf(float from, float to, float t)
{
	t = ft_clampf_0_1(t);
	t = -2.0f * t * t * t + 3.0f * t * t;
	return (to * t + from * (1.0f - t));
}
