/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:40:39 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/06/27 15:35:58 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H

# define FT_STRING_H

# include "ft_math.h"
# include "ft_heap.h"

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>

size_t	ft_strlen(const char *s);
double	ft_atod(const char *s);
float	ft_atof(const char *s);
int32_t	ft_atoi(const char *s);
int64_t	ft_atol(const char *s);
int32_t	ft_atox(const char *s);
char	*ft_itoa(int32_t n);
char	**ft_strsplit(
			const char *__restrict__ s,
			const char *__restrict__ set
			);
char	*ft_strchr(const char *s, int32_t c);
char	*ft_strdup(const char *s);
bool	ft_strequals(const char *lhs, const char *rhs);
void	ft_striteri(char *s, void (*f)(uint32_t, char*));
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strmapi(const char *s, char (*f)(uint32_t, char));
int32_t	ft_strcmp(const char *s1, const char *s2);
int32_t	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int32_t c);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_substr(const char *s, uint32_t start, size_t len);
char	*ft_strnjoin(char **strings, size_t n);
char	*ft_strchrnul(const char *s, int32_t c);
size_t	ft_strspn(const char *s, const char *set);
size_t	ft_strcspn(const char *s, const char *set);
char	*ft_strpbrk(const char *s, const char *b);
char	*ft_strtok(char *__restrict__ s, const char *__restrict__ sep);
char	*ft_strtok_r(
			char *__restrict__ s,
			const char *__restrict__ sep,
			char **__restrict__ p
			);
int32_t	ft_toupper(int32_t c);
int32_t	ft_tolower(int32_t c);
int32_t	ft_isalnum(int32_t c);
int32_t	ft_isalpha(int32_t c);
int32_t	ft_isascii(int32_t c);
int32_t	ft_isdigit(int32_t c);
int32_t	ft_isprint(int32_t c);
int32_t	ft_issign(int32_t c);
int32_t	ft_isspace(int32_t c);
int32_t	ft_isint(const char *s);
int32_t	ft_isfloat(const char *s);
char	*ft_swapcase(const char *s);

#endif
