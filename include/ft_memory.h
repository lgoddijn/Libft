/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:41:07 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/10/13 20:21:04 by lgoddijn         ###   ########.fr       */
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

# include "ft_values.h"

typedef unsigned char	t_byte;

__always_inline bool	ft_isnull(void *ptr)
{
	return (ptr == NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int32_t c, size_t n);
int32_t	ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memset(void *s, int32_t c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);
bool	ft_memequals(const void *lhs, const void *rhs);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_realloc(void *ptr, size_t size);
void	ft_free2d(void **ptr);

#endif
