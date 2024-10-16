/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirent.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 00:23:18 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/10/16 15:49:12 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DIRENT_H

# define FT_DIRENT_H

# include "ft_syscall.h"
# include "ft_unistd.h"
# include "ft_memory.h"
# include "ft_vector.h"
# include "ft_string.h"

# include <dirent.h>
# include <stdlib.h>
# include <stdint.h>
# include <errno.h>
# include <stddef.h>
# include <fcntl.h>
# include <limits.h>
# include <sys/stat.h>

/* Cuz DIR struct is opaque */
typedef struct s_dirstream
{
	off_t			tell;
	int				fd;
	int				buf_pos;
	int				buf_end;
	volatile int	lock[1];
	char			buf[2048];
}	t_dir;

typedef struct s_scandir_args
{
	const char		*path;
	struct dirent	***res;
	int				(*sel)(const struct dirent*);
	int				(*cmp)(const struct dirent **, const struct dirent **);
}	t_scandir_args;

typedef struct s_scandir_locale
{
	struct dirent	**names;
	struct dirent	**tmp;
	struct dirent	*de;
	size_t			cnt;
	size_t			len;
	int				oerrno;
}	t_scandir_locale;

static
inline size_t	__offsetof(void)
{
	return ((size_t)((char *)&(((struct s_dirstream *)0)->buf) - (char *)0));
}

typedef char	t_dirstream_buf_alignment_check[1 - 2 * (int)(offsetof(
					struct s_dirstream, buf) % sizeof(off_t))];

int				ft_alphasort(
					const struct dirent **a,
					const struct dirent **b);
t_dir			*ft_opendir(const char *path);
int				ft_closedir(t_dir *dir);
struct dirent	*ft_readdir(t_dir *dir);
int				ft_readdir_r(
					t_dir *__restrict__ dir,
					struct dirent *__restrict__ buf,
					struct dirent **__restrict__ result);
void			ft_seekdir(t_dir *dir, long off);
void			ft_rewinddir(t_dir *dir);
t_dir			*ft_fdopendir(int fd);
ssize_t			ft_posix_getdents(
					int fd,
					void *buf,
					size_t len,
					int flags);
int				ft_scandir(t_scandir_args *args);

static __inline__ int	ft_dirfd(t_dir *d)
{
	return (d->fd);
}

static __inline__ long	ft_telldir(t_dir *dir)
{
	return (dir->tell);
}

#endif
