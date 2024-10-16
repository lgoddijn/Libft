/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirent.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 00:23:18 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/10/16 02:04:23 by lgoddijn         ###   ########.fr       */
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

struct s_dirstream
{
	off_t			tell;
	int				fd;
	int				buf_pos;
	int				buf_end;
	volatile int	lock[1];
	char			buf[2048];
};

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
DIR				*ft_opendir(const char *name);
int				ft_closedir(DIR *dir);
struct dirent	*ft_readdir(DIR *dir);
int				ft_readdir_r(
					DIR *__restrict__ dir,
					struct dirent *__restrict__ buf,
					struct dirent **__restrict__ result);
void			seekdir(DIR *dir, long off);
void			ft_rewinddir(DIR *dir);
DIR				*ft_fdopendir(int fd);
ssize_t			ft_posix_getdents(
					int fd,
					void *buf,
					size_t len,
					int flags);

static __inline__ int	ft_dirfd(DIR *d)
{
	return (d->fd);
}

static __inline__ long	ft_telldir(DIR *dir)
{
	return (dir->tell);
}

#endif
