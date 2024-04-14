/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:33:51 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/14 19:23:19 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H

# define FT_MATH_H

# include "ft_values.h"

# include <stdlib.h>
# include <math.h>
# include <stdbool.h>
# include <stdint.h>

union u_sqrtf
{
	float		d;
	t_bitmask32	i;
};

union u_sqrtd
{
	double		d;
	t_bitmask64	i;
};

union u_absf
{
	float		f;
	t_bitmask32	i;
};

union u_absd
{
	double		f;
	t_bitmask64	i;
};

int32_t		ft_abs(int32_t x);
double		ft_absd(double x);
float		ft_absf(float x);
int32_t		ft_clamp_0_1(int32_t value);
int32_t		ft_clamp(int32_t value, int32_t min, int32_t max);
double		ft_clampd_0_1(double value);
double		ft_clampd(double value, double min, double max);
float		ft_clampf_0_1(float value);
float		ft_clampf(float value, float min, float max);
double		ft_delta_angled(double current, double target);
float		ft_delta_anglef(float current, float target);
size_t		ft_digits(int64_t n);
int32_t		ft_pow(int32_t base, int32_t exp);
double		ft_powd(double base, int32_t exp);
float		ft_powf(float base, int32_t exp);
double		ft_expd(double x);
float		ft_expf(float x);
int32_t		ft_sign(int32_t n);
double		ft_signd(double f);
float		ft_signf(float f);
float		ft_sqrtf(float n);
double		ft_sqrtd(double n);
float		ft_rsqrtf(float n);
double		ft_rsqrtd(double n);
int32_t		ft_max(int32_t a, int32_t b);
double		ft_maxd(double a, double b);
float		ft_maxf(float a, float b);
int32_t		ft_min(int32_t a, int32_t b);
double		ft_mind(double a, double b);
float		ft_minf(float a, float b);
int32_t		ft_mod(int32_t x, int32_t y);
double		ft_modd(double x, double y);
float		ft_modf(float x, float y);
bool		ft_approximatelyd(double a, double b);
bool		ft_approximatelyf(float a, float b);
uint64_t	ft_factorial(int32_t n);
double		ft_gammad(double value, double absmax, double gamma);
float		ft_gammaf(float value, float absmax, float gamma);
double		ft_gaussian_kerneld(double d, double sigma);
float		ft_gaussian_kernelf(float d, float sigma);
double		ft_lerpd_angle(double current, double target, double t);
double		ft_lerpd_unclamped(double a, double b, double t);
double		ft_lerpd(double a, double b, double t);
float		ft_lerpf_angle(float current, float target, float t);
float		ft_lerpf_unclamped(float a, float b, float t);
float		ft_lerpf(float a, float b, float t);
double		ft_logd(double x);
float		ft_logf(float x);
int32_t		ft_move_towards(
				int32_t current,
				int32_t target,
				int32_t max_delta);
double		ft_move_towardsd(
				double current,
				double target,
				double max_delta);
float		ft_move_towardsf(
				float current,
				float target,
				float max_delta);
double		ft_move_towards_angled(
				double current,
				double target,
				double max_delta);
float		ft_move_towards_anglef(
				float current,
				float target,
				float max_delta);
double		ft_smooth_stepd(double from, double to, double t);
float		ft_smooth_stepf(float from, float to, float t);

#endif
