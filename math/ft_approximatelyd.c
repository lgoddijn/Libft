/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_approximatelyd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 22:13:39 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/29 22:14:07 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

bool	ft_approximatelyd(double a, double b)
{
	return (ft_absd(b - a) < ft_maxd(
			1.0E-6 * ft_maxd(ft_absd(a),
				ft_absd(b)), FLOAT_MIN_DENORMAL * 8.0));
}
