/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:34:16 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/31 12:52:30 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H

# define FT_VECTOR_H

# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <math.h>

# include "ft_values.h"

typedef struct s_vector2
{
	float	x;
	float	y;
}	t_vector2;

typedef struct s_vector3
{
	float	x;
	float	y;
	float	z;
}	t_vector3;

t_vector3	ft_init_v3(float x, float y, float z);
t_vector3	ft_add_v3(t_vector3 a, t_vector3 b);
t_vector3	ft_sub_v3(t_vector3 a, t_vector3 b);
float		ft_sum_v3(t_vector3 v);
float		ft_remains_v3(t_vector3 v);
float		ft_product_v3(t_vector3 v);
float		ft_mean_v3(t_vector3 v);
t_vector3	ft_scale_v3(t_vector3 v, float k);
t_vector3	ft_mul_v3(t_vector3 a, t_vector3 b);
t_vector3	ft_div_v3(t_vector3 a, t_vector3 b);
t_vector3	ft_sdiv_v3(t_vector3 v, float k);
float		ft_dot_v3(t_vector3 a, t_vector3 b);
float		ft_sqr_magnitude_v3(t_vector3 v);
float		ft_magnitude_v3(t_vector3 v);
t_vector3	ft_normalize_v3(t_vector3 v);
t_vector3	ft_conjugate_v3(t_vector3 v);
t_vector3	ft_lerp_unclamped_v3(t_vector3 a, t_vector3 b, float t);
t_vector3	ft_lerp_v3(t_vector3 a, t_vector3 b, float t);
t_vector3	ft_move_towards_v3(
				t_vector3 current,
				t_vector3 target,
				float max_distance_delta);
t_vector3	ft_cross_v3(t_vector3 lhs, t_vector3 rhs);
bool		ft_equals_v3(t_vector3 a, t_vector3 b);
t_vector3	ft_reflect_v3(t_vector3 in_direction, t_vector3 in_normal);
t_vector3	ft_project_v3(t_vector3 in_direction, t_vector3 on_normal);
t_vector3	ft_aggregate_v3(t_vector3 *vectors, size_t size, float t);
float		ft_angle_v3(t_vector3 from, t_vector3 to);
float		ft_signed_angle_v3(t_vector3 from, t_vector3 to, t_vector3 axis);
float		ft_distance_v3(t_vector3 a, t_vector3 b);
t_vector3	ft_clamp_magnitude_v3(t_vector3 v, float max_len);
t_vector3	ft_min_v3(t_vector3 lhs, t_vector3 rhs);
t_vector3	ft_max_v3(t_vector3 lhs, t_vector3 rhs);
t_vector3	ft_slerp_v3(t_vector3 v1, t_vector3 v2, float t);

#endif
