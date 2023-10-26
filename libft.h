/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:48:53 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/19 17:11:42 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/*

@make
	The make file contains all mandatory functions in the `all` rule.
	The bonus functions are contained under the `bonus` rule.
	The extra functions will be contained under the `extra` rule.
	All functions will have their own respective category and
	`all` will be used to compile them all, due to the subject not right now.

	Ex.
		`make fclean all`, `make fclean bonus`, `make fclean extra`;

@notes
	For documentation go to the respective `*.c` file
	Each function has its own `*.c` file named after it.

	Extra functions are defined in the respective parent function's `*.c` file.
	They will always be defined as `static` to maintain the scope within that file.

	Prototypes are split by usage cases.

	New functions will be added as time goes on.

	All new typedefs will be stored in this header file.

	All constants will be defined as `macro` (ex. #define KEPSILON 1E-05f).

*/

/*
----------------------------------
		Constants & Macros
----------------------------------
*/

// When you can't return NULL or -1
// This is just an int bool ig
// This works for both long and int

# define C_0K_LMA0				0xC0FFEE
# define K0_C_LMA0				-0xDEAD

# define PI						3.14159265358979323846
# define E						2.71828182845904523536
# define GOLDEN_RATIO			1.618033988749895
# define SQRT2					1.4142135623730951
# define SQRT3					1.7320508075688772
# define FLOAT_MIN_NORMAL		1.17549435E-38f
# define FLOAT_MIN_DENORMAL		1.401298E-45
# define KEPSILON				1E-05f
# define KEPSILON_NORMAL_SQRT	1E-15f
# define EARTH_GRAVITY			9.81
# define K_FACTOR				3
# define BITMAP_32_SIZE			32
# define BITMAP_64_SIZE			64
# define SCHOOL_42_HAHA			42
# define ALPHABET_SIZE			26
# define BUFFER_SIZE			1024
# define DEG2RAD				PI / 180.0f
# define RAD2DEG				57.29578f
# define HUGE_VALF				__builtin_huge_valf()
# define HUGE_VALL				__builtin_huge_vall()
# define INFINITY				__builtin_inf()
# define NAN					__builtin_nan("")

/*
--------------------------
		Structures
--------------------------
*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_file
{
	int		fd;
	char	*content;
}	t_file;

typedef	struct s_vector2
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

typedef struct s_vector4
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_vector4;

typedef struct s_force2
{
	float		magnitude;
	t_vector2	direction;
}	t_force2;

typedef struct s_force3
{
	float		magnitude;
	t_vector3	direction;
}	t_force3;

typedef struct s_force4
{
	float		magnitude;
	t_vector4	direction;
}	t_force4;

typedef struct s_matrix2
{
	float	cells[2][2];
}	t_matrix2;

typedef struct s_matrix3
{
	float	cells[3][3];
}	t_matrix3;

typedef struct s_matrix4
{
	float	cells[4][4];
}	t_matrix4;

typedef struct s_matrixnd
{
	float	**cells;
	size_t	X_shape;
	size_t	y_shape;
}	t_matrixnd;

typedef struct s_quaternion
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_quaternion;

typedef struct s_particle2
{
	t_vector2	position;
	t_vector2	velocity;
	t_vector2	acceleration;
	float		mass;
	float		charge;
	t_force2	force;
}	t_particle2;

typedef struct s_particle3
{
	t_vector3	position;
	t_vector3	velocity;
	t_vector3	acceleration;
	float		mass;
	float		charge;
	t_force3	force;
}	t_particle3;

typedef struct s_particle4
{
	t_vector4	position;
	t_vector4	velocity;
	t_vector4	acceleration;
	float		mass;
	float		charge;
	t_force4	force;
}	t_particle4;

typedef struct s_collider
{
	float	width;
	float	height;
	float	depth;
}	t_collider;

typedef struct s_sphere_collider
{
	t_vector3	center;
	float		radius;
}	t_sphere_collider;

typedef struct s_box_collider
{
	t_vector3	min;
	t_vector3	max;
}	t_box_collider;

typedef struct s_rigid_body
{
    t_vector3	position;
    t_vector3	velocity;
    t_vector3	acceleration;
    t_vector3	angular_velocity;
    t_vector3	angular_acceleration;
    float		mass;
    float		drag;
    float		angular_drag;
    t_matrix3	intertia_tensor;
    t_collider	collider;
}   t_rigid_body;

typedef struct s_ray2
{
    t_vector2	origin;
    t_vector2	direction;
}   t_ray2;

typedef struct s_ray3
{
    t_vector3	origin;
    t_vector3	direction;
}	t_ray3;

typedef struct s_ray4
{
	t_vector4	origin;
	t_vector4	direction;
}	t_ray4;

typedef unsigned int		t_bitmask32;
typedef unsigned long long	t_bitmask64;

typedef struct s_bitmap32
{
	t_bitmask32	bits[BITMAP_32_SIZE / (sizeof(t_bitmask32) * 8)];
}	t_bitmap32;

typedef struct s_bitmap64
{
	t_bitmask64	bits[BITMAP_64_SIZE / (sizeof(t_bitmask64) * 8)];
}	t_bitmap64;

typedef struct s_color
{
	float	r;
	float	g;
	float	b;
	float	a;
}	t_color;

typedef struct s_color32
{
	t_bitmask32	bits;
}	t_color32;

typedef struct s_color64
{
	t_bitmask64	bits;
}	t_color64;

typedef struct s_color_hex_str
{
	char	*hex;
}	t_color_hex_str;

typedef struct s_color_hex
{
	unsigned long long	hex;
}	t_color_hex;

typedef struct s_ansi_color
{
	char	*ansi;
}	t_ansi_color;

typedef struct s_gradient
{
	t_color	lower_bound;
	t_color	upper_bound;
}	t_gradient;

typedef struct s_rectangle
{
	float	x;
	float	y;
	float	width;
	float	height;
}	t_rectangle;

typedef struct s_bounds2
{
	t_vector2	center;
	t_vector2	extents;
}	t_bounds2;

typedef struct s_bounds3
{
	t_vector3	center;
	t_vector3	extents;
}	t_bounds3;

typedef struct s_bounds4
{
	t_vector4	center;
	t_vector4	extents;
}	t_bounds4;

typedef struct s_plane2
{
	t_vector2	normal;
	float		distance;
}	t_plane2;

typedef struct s_plane3
{
	t_vector3	normal;
	float		distance;
}	t_plane3;

typedef struct s_plane4
{
	t_vector4	normal;
	float		distance;
}	t_plane4;

typedef struct s_contact_point2
{
	t_vector2	point;
	t_vector2	normal;
}	t_contact_point2;

typedef struct s_contact_point3
{
	t_vector3	point;
	t_vector3	normal;
}	t_contact_point3;

typedef struct s_contact_point4
{
	t_vector4	point;
	t_vector4	normal;
}	t_contact_point4;

typedef struct s_keyframe
{
	float	time;
	float	value;
	float	in_tangent;
	float	out_tangent;
}	t_keyframe;

typedef struct s_uv_cords
{
	float	u;
	float	v;
}	t_uv_cords;

typedef struct s_ui_char_style
{
	char		*family;
	char		*style;
	uint16_t	size;
	uint16_t	weight;
	t_color32	color;
	uint8_t		underline;
	uint8_t		strikethrough;
	uint8_t		kerning;
	uint8_t		smallCaps;
}	t_ui_char_style;

typedef struct s_ui_vertex
{
	t_vector2	position;
	t_color		color;
	t_uv_cords	cords;
}	t_ui_vertex;

typedef struct s_ui_char_info
{
	char			c;
	int				ascii_index;
    t_ui_char_style	style;
}	t_ui_char_info;

typedef struct s_ui_line_info
{
	t_ray2		ray;
	t_vector2	end;
	t_color		color;
}	t_ui_line_info;

typedef struct s_resolution
{
	int	width;
	int	height;
	int	refresh_rate;
}	t_resolution;

typedef struct s_hash64
{
	unsigned char	value[8];
}	t_hash64;

typedef struct s_hash128
{
	unsigned char	value[16];
}	t_hash128;

typedef struct s_dict
{
	void			*key;
	void			*value;
	struct s_dict	*next;
}	t_dict;

typedef struct s_hash_map
{
	size_t	size;
	t_dict	**array;
}	t_hash_map;

typedef struct s_hash_table
{
	size_t			size;
	t_dict			**array;
	pthread_mutex_t	mutex;
}	t_hash_table;

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

typedef struct s_binary_tree
{
	void					*content;
    struct s_binary_tree	*left;
    struct s_binary_tree	*right;
}	t_binary_tree;

typedef struct s_ktree
{
    void			*content;
    struct s_ktree	*children[K_FACTOR];
}	t_ktree;

typedef struct s_avl_tree
{
	void				*content;
	struct s_avl_tree	*left;
	struct s_avl_tree	*right;
	size_t				height;
}	t_avl_tree;

typedef struct s_trie
{
	struct s_trie	*children[ALPHABET_SIZE];
	bool			is_end_of_word;
}	t_trie;

typedef struct s_graph_node
{
	int					vertex;
	struct s_graph_node	*next;
}	t_graph_node;

typedef struct s_binary_heap
{
	void	*content;
	size_t	size;
	size_t	cap;
}	t_binary_heap;

/*
-----------------------------------
		String IS Functions
-----------------------------------
*/

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

/*
-----------------------------------
		String TO Functions
-----------------------------------
*/

int		ft_toupper(int c);
int		ft_tolower(int c);

/*
------------------------------------
		Allocation Functions
------------------------------------
*/

void	*ft_calloc(size_t nmemb, size_t size);

/*
--------------------------------
		Memory Functions
--------------------------------
*/

void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);

/*
--------------------------------
		String Functions
--------------------------------
*/

size_t	ft_strlen(const char *s);
int		ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/*
-----------------------------------------
		File Descriptor Functions
-----------------------------------------
*/

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/*
-------------------------------------
		Linked List Functions
-------------------------------------
*/

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif // LIBFT_H