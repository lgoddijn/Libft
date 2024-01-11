/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:33:51 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/01/11 15:38:50 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H

# define FT_MATH_H

# include "ft_values.h"

# include <stdlib.h>
# include <math.h>
# include <stdbool.h>

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

int					ft_abs(int x);
double				ft_absd(double x);
float				ft_absf(float x);
int					ft_clamp_0_1(int value);
int					ft_clamp(int value, int min, int max);
double				ft_clampd_0_1(double value);
double				ft_clampd(double value, double min, double max);
float				ft_clampf_0_1(float value);
float				ft_clampf(float value, float min, float max);
double				ft_delta_angled(double current, double target);
float				ft_delta_anglef(float current, float target);
size_t				ft_digits(long n);
int					ft_pow(int base, int exp);
double				ft_powd(double base, int exp);
float				ft_powf(float base, int exp);
double				ft_expd(double x);
float				ft_expf(float x);
int					ft_sign(int n);
double				ft_signd(double f);
float				ft_signf(float f);
float				ft_sqrtf(float n);
double				ft_sqrtd(double n);
float				ft_rsqrtf(float n);
double				ft_rsqrtd(double n);
int					ft_max(int a, int b);
double				ft_maxd(double a, double b);
float				ft_maxf(float a, float b);
int					ft_min(int a, int b);
double				ft_mind(double a, double b);
float				ft_minf(float a, float b);
int					ft_mod(int x, int y);
double				ft_modd(double x, double y);
float				ft_modf(float x, float y);
bool				ft_approximatelyd(double a, double b);
bool				ft_approximatelyf(float a, float b);
unsigned long long	ft_factorial(int n);
double				ft_gammad(double value, double absmax, double gamma);
float				ft_gammaf(float value, float absmax, float gamma);
double				ft_gaussian_kerneld(double d, double sigma);
float				ft_gaussian_kernelf(float d, float sigma);
double				ft_lerpd_angle(double current, double target, double t);
double				ft_lerpd_unclamped(double a, double b, double t);
double				ft_lerpd(double a, double b, double t);
float				ft_lerpf_angle(float current, float target, float t);
float				ft_lerpf_unclamped(float a, float b, float t);
float				ft_lerpf(float a, float b, float t);
double				ft_logd(double x);
float				ft_logf(float x);
int					ft_move_towards(
						int current,
						int target,
						int max_delta);
double				ft_move_towardsd(
						double current,
						double target,
						double max_delta);
float				ft_move_towardsf(
						float current,
						float target,
						float max_delta);
double				ft_move_towards_angled(
						double current,
						double target,
						double max_delta);
float				ft_move_towards_anglef(
						float current,
						float target,
						float max_delta);
double				ft_smooth_stepd(double from, double to, double t);
float				ft_smooth_stepf(float from, float to, float t);

#endif
