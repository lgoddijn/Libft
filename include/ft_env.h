/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:33:05 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/10/13 18:16:41 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENV_H

# define FT_ENV_H

# include <stdlib.h>
# include <unistd.h>

# include "ft_string.h"

void	__envp_rm_add(char *old, char *new);
void	__env_rm_add(char *old, char *new);

int		ft_clearenv(void);
int		ft_clearenvp(char ***envp);

char	*ft_getenv(const char *__restrict__ key);
char	*ft_getenvp(const char *__restrict__ key, char **__envp);

int		ft_putenv_heap(char *__restrict__ s, char *__restrict__ r);
int		ft_putenv(char *__restrict__ s);

int		ft_putenvp_heap(
			char *__restrict__ s,
			char *__restrict__ r,
			char ***__envp);
int		ft_putenvp(char *__restrict__ s, char ***__envp);

int		ft_setenv(
			const char *__restrict__ key,
			const char *__restrict__ value);
int		ft_setenvp(
			const char *__restrict__ key,
			const char *__restrict__ value,
			char ***__envp);

int		ft_unsetenv(const char *__restrict__ key);
int		ft_unsetenvp(const char *__restrict__ key, char ***__envp);

#endif
