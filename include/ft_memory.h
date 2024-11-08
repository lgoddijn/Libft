/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:41:07 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/08 21:09:20 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_H

# define FT_MEMORY_H

# include <sys/types.h>
# include <stdbool.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <limits.h>

# include "ft_values.h"

# define __WORD_SIZE	8

typedef unsigned char										t_byte;
typedef size_t __attribute__ ((__may_alias__))				t_word;
typedef uint32_t __attribute__((__may_alias__))				t_u32;
typedef uint64_t __attribute__((__may_alias__))				t_u64;
typedef size_t __attribute__((__may_alias__))				t_wt;

static __always_inline int	ft_isnull(void *ptr)
{
	return (!ptr);
}

void	*ft_memcpy(
								void *__restrict__ dst,
								const void *__restrict__ src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memset(void *dst, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memrchr(const void *m, int c, size_t n);
void	ft_bzero(void *s, size_t n);
bool	ft_memequals(const void *lhs, const void *rhs);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_realloc(void *p, size_t psize, size_t size);
void	ft_free2d(void **ptr);

#endif
