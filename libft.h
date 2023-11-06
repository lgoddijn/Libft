/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:48:53 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/11/06 18:15:03 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

@make
	All functions will now compile under the `all` rule.
	Since theres no more bonus' to comply to.

	Ex.
		`make fclean all`

@notes
	For documentation go to the respective `*.c` file
	Each function has its own `*.c` file named after it.
	(Given that I'm not too lazy to write it).

	Prototypes are split by usage cases.

	New functions will be added as time goes on.

	All new typedefs will be stored in this header file.

	All constants will be defined as macro definitions
	(ex. #define KEPSILON 1E-05f).

	The bonus functions were renamed to be more semantic.
	You can find them in the linked list sub-directory.

*/

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <complex.h>
# include <math.h>

# pragma region macros

// When you can't return NULL or -1
// This is just an int bool ig
// This works for both long and int

# define C_0K_LMA0				0xC0FFEE
# define K0_C_LMA0				-0xDEAD

// Other (less cool) stuff...

# define PI						3.14159265358979323846

# define E						2.71828182845904523536

# define GOLDEN_RATIO			1.618033988749895

# define SQRT2					1.4142135623730951
# define SQRT3					1.7320508075688772

# define FLOAT_MIN_NORMAL		1.17549435E-38f
# define FLOAT_MIN_DENORMAL		1.401298E-45f

# define KEPSILON				1.0E-05f
# define KEPSILON_NORMAL_SQRT	1.0E-15f

# define EARTH_GRAVITY			9.81f

# define K_FACTOR				3

# define BITMAP_32_SIZE			32
# define BITMAP_64_SIZE			64

# define EN_ALPHABET_SIZE		26

# define BUFFER_SIZE			1024

# define DEG2RAD				0.01745329251994329576923690768489
# define RAD2DEG				57.2957795130823208767981548141050

# pragma endregion macros

# pragma region types

/*

Some of these dont have their own
functions yet. This is just for
time management since I don't
need them yet. But I find the
structs / types useful to have
for future reference.

*/

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

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_file
{
	int				fd;
	char			*content;
	struct s_file	*next;
}	t_file;

typedef unsigned int		t_bitmask32;
typedef unsigned long long	t_bitmask64;

typedef struct s_bitmap32
{
	t_bitmask32	bits[BITMAP_32_SIZE \
		/ (sizeof(t_bitmask32) * 8)];
}	t_bitmap32;

typedef struct s_bitmap64
{
	t_bitmask64	bits[BITMAP_64_SIZE \
		/ (sizeof(t_bitmask64) * 8)];
}	t_bitmap64;

typedef struct s_color
{
	float	r;
	float	g;
	float	b;
	float	a;
}	t_color;

typedef struct s_dict
{
	void			*key;
	void			*value;
	struct s_dict	*next;
}	t_dict;

typedef struct s_stack
{
	int		top;
	size_t	cap;
	void	*content;
}	t_stack;

typedef struct s_queue
{
	int		front;
	int		rear;
	size_t	size;
	size_t	cap;
	void	*array;
}	t_queue;

# pragma endregion types

# pragma region memory

void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);

# pragma endregion memory

# pragma region string

size_t				ft_strlen(const char *s);
int					ft_atoi(const char *nptr);
char				*ft_itoa(int n);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s);
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(
						const char *big,
						const char *little,
						size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strshove(const char *s1, const char *s2);
char				*ft_strnshove(char **strings, size_t n, bool should_free);
char				*ft_strshove_wild(const char *s1, ...);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);

# pragma endregion string

# pragma region file

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*get_next_line(int fd);

# pragma endregion file

# pragma region linkedlist

t_list				*ft_init_lst(void *content);
void				ft_prepend_lst(t_list **lst, t_list *node);
size_t				ft_size_lst(t_list *lst);
t_list				*ft_last_lst(t_list *lst);
void				ft_append_lst(t_list **lst, t_list *node);
void				ft_del_one_lst(t_list *lst, void (*del)(void*));
void				ft_clear_lst(t_list **lst, void (*del)(void*));
void				ft_iter_lst(t_list *lst, void (*f)(void *));
t_list				*ft_map_lst(
						t_list *lst,
						void *(*f)(void *),
						void (*del)(void *));

# pragma endregion linkedlist

# pragma region math

/*

These unions are just to
not get screamed at by
the compiler. Since ptr
casting stuff is illegal
or smth. Not sure. Regardless,
this is what must be done.

Otherwise I would just do this:

void	unholy_absd(double *a)
{
	*((bitmask64 *)a) &= ~(1UL << 63);
}

*/

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

# pragma endregion math

# pragma region vector3_functions

t_vector3			ft_init_v3(float x, float y, float z);
t_vector3			ft_add_v3(t_vector3 a, t_vector3 b);
t_vector3			ft_sub_v3(t_vector3 a, t_vector3 b);
t_vector3			ft_scale_v3(t_vector3 v, float k);
t_vector3			ft_div_v3(t_vector3 a, t_vector3 b);
t_vector3			ft_sdiv_v3(t_vector3 v, float k);
float				ft_dot_v3(t_vector3 a, t_vector3 b);
float				ft_sqr_magnitude_v3(t_vector3 v);
float				ft_magnitude_v3(t_vector3 v);
t_vector3			ft_normalize_v3(t_vector3 v);
t_vector3			ft_conjugate_v3(t_vector3 v);
t_vector3			ft_lerp_unclamped_v3(t_vector3 a, t_vector3 b, float t);
t_vector3			ft_lerp_v3(t_vector3 a, t_vector3 b, float t);
t_vector3			ft_move_towards_v3(
						t_vector3 current,
						t_vector3 target,
						float max_distance_delta);
t_vector3			ft_cross_v3(t_vector3 lhs, t_vector3 rhs);
bool				ft_equals_v3(t_vector3 a, t_vector3 b);
t_vector3			ft_reflect_v3(t_vector3 in_direction, t_vector3 in_normal);
t_vector3			ft_project_v3(t_vector3 in_direction, t_vector3 on_normal);
t_vector3			ft_aggregate_v3(t_vector3 *vectors, size_t size, float t);
float				ft_angle_v3(t_vector3 from, t_vector3 to);
float				ft_signed_angle_v3(
						t_vector3 from,
						t_vector3 to,
						t_vector3 axis);
float				ft_distance_v3(t_vector3 a, t_vector3 b);
t_vector3			ft_clamp_magnitude_v3(t_vector3 v, float max_len);
t_vector3			ft_min_v3(t_vector3 lhs, t_vector3 rhs);
t_vector3			ft_max_v3(t_vector3 lhs, t_vector3 rhs);
t_vector3			ft_slerp_v3(t_vector3 v1, t_vector3 v2, float t);

# pragma endregion vector3_functions

#endif // LIBFT_H