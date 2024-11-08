/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirent.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 00:23:18 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/10/16 17:42:05 by lgoddijn         ###   ########.fr       */
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

typedef struct s_kernel_dirent
{
	unsigned long	d_ino;
	unsigned long	d_off;
	unsigned short	d_reclen;
	char			d_name[];
}	t_kernel_dirent;

/*	Stupid kernel is outdated,
	dirent kernel struct doesn't
	match userspace dirent struct */
static __inline__
struct dirent				*__align_kernel_dirent(t_kernel_dirent *lde)
{
	static struct dirent	de;

	de.d_ino = lde->d_ino;
	de.d_off = lde->d_off;
	de.d_reclen = lde->d_reclen;
	ft_memcpy(de.d_name, lde->d_name, sizeof(de.d_name) - 1);
	de.d_name[sizeof(de.d_name) - 1] = '\0';
	de.d_type = 0;
	return (&de);
}

/* Compile time alignment check */
typedef char	t_dirstream_buf_alignment_check[1 - 2 * (int)(
					offsetof(t_dir, buf) % sizeof(off_t))];

int							ft_alphasort(
								const struct dirent **a,
								const struct dirent **b);
t_dir						*ft_opendir(const char *path);
int							ft_closedir(t_dir *dir);
struct dirent				*ft_readdir(t_dir *dir);
int							ft_readdir_r(
								t_dir *__restrict__ dir,
								struct dirent *__restrict__ buf,
								struct dirent **__restrict__ result);
void						ft_seekdir(t_dir *dir, long off);
void						ft_rewinddir(t_dir *dir);
t_dir						*ft_fdopendir(int fd);
ssize_t						ft_posix_getdents(
								int fd,
								void *buf,
								size_t len,
								int flags);
int							ft_scandir(t_scandir_args *args);

static __always_inline int	ft_dirfd(t_dir *d)
{
	return (d->fd);
}

static __always_inline long	ft_telldir(t_dir *dir)
{
	return (dir->tell);
}

#endif
