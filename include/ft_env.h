/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:33:05 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/07/31 12:40:46 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENV_H

# define FT_ENV_H

# include <stdlib.h>
# include <unistd.h>

# include "ft_string.h"

void	__env_rm_add(char *__restrict__ old, char *__restrict__ new);
char	*ft_getenv(const char *__restrict__ key);
int32_t	ft_putenv_heap(char *__restrict__ s, char *__restrict__ r);
int32_t	ft_putenv(char *__restrict__ s);
int32_t	ft_setenv(
			const char *__restrict__ key,
			const char *__restrict__ value);
int32_t	ft_unsetenv(const char *__restrict__ key);

#endif
