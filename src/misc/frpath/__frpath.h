/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __frpath.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:22:28 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/11 23:02:39 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRPATH_H

# define __FRPATH_H

# include "../../../include/ft_misc.h"

# include <unistd.h>
# include <string.h>

typedef struct s_loc
{
	char	stk[PATH_MAX + 1];
	char	out[PATH_MAX];
	size_t	p;
	size_t	q;
	ssize_t	k;
	size_t	l;
	size_t	l0;
	int		parent;
	size_t	nparent;
	int		do_readlink;
	int		check_directory;
}	t_loc;

typedef enum e_loop_status
{
	DEFAULT,
	CONTINUE,
	BREAK,
	RETNULL,
	RETRES,
}	t_lstatus;

static __always_inline t_lstatus	__toolongl(void)
{
	errno = ENAMETOOLONG;
	return (RETNULL);
}

static __always_inline void	*__toolong(void)
{
	errno = ENAMETOOLONG;
	return (NULL);
}

static __always_inline size_t	__slash_count(const char *__restrict__ s)
{
	const char	*s0 = s;

	while (*s == '/')
		++s;
	return (s - s0);
}

static __always_inline void	*__memcpy_fallback(
		void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dst || !src)
		return (dst);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dst);
}

t_loc		*__init(const char *__restrict__ path, t_loc *lc);

t_lstatus	__do_absolute(t_loc *lc);
t_lstatus	__do_readlink(t_loc *lc);
t_loc		*__do_resolv_loop(t_loc *lc);
t_loc		*__finalize_stack(t_loc *lc);

#endif
