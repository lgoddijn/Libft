/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:33:05 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/10/14 17:48:42 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENV_H

# define FT_ENV_H

# include <stdlib.h>
# include <unistd.h>

# include "ft_memory.h"
# include "ft_string.h"

typedef struct s_args1
{
	char	*s;
	char	*r;
	size_t	i;
	size_t	l;
	char	***__envp;
}	t_args1;

typedef struct s_args2
{
	char	***__envp;
	char	*r;
	size_t	i;
}	t_args2;

void	__envp_rm_add(char *old, char *new);
void	__env_rm_add(char *old, char *new);

int		ft_clearenv(void);
int		ft_clearenvp(char ***envp);

char	*ft_getenv(const char *__restrict__ key);
char	*ft_getenvp(const char *__restrict__ key, char **__envp);

int		__ft_putenv(char *s, size_t l, char *r);
int		ft_putenv(char *s);

int		__ft_putenvp(char *s, size_t l, char *r, char ***__envp);
int		ft_putenvp(char *s, char ***__envp);

int		ft_setenv(const char *var, const char *value, int overwrite);
int		ft_setenvp(
			const char *var,
			const char *value,
			int overwrite,
			char ***__envp);

int		ft_unsetenv(const char *__restrict__ key);
int		ft_unsetenvp(const char *__restrict__ key, char ***__envp);

#endif
