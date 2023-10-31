/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lerpf_angle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:45:12 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/29 15:15:56 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

float	ft_lerpf_angle(float current, float target, float t)
{
	return (current + ft_delta_anglef(current, target) * ft_clampf_0_1(t));
}
