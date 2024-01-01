/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unistd.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:01:20 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/01/01 20:12:01 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UNISTD_H

# define FT_UNISTD_H

# include <stdlib.h>
# include <stdint.h>
# include <sys/types.h>
# include <sys/syscall.h>
# include <sys/sysinfo.h>
# include <sys/utsname.h>
# include <string.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdbool.h>

# include "ft_internal.h"
# include "ft_values.h"

int			ft_access(const char *__path, int __mode);
uint32_t	ft_alarm(uint32_t seconds);
int			ft_chmod(const char *__path, mode_t __mode);
int			ft_chown(const char *__path, uid_t __uid, gid_t __gid);
int			ft_chdir(const char *__path);
int			ft_dup(int __fd);
int			ft_dup2(int __old, int __new);
void		ft_exit(int __status);
int			ft_fchdir(int __fd);
int			ft_fchown(int __fd, uid_t __uid, gid_t __gid);
int			ft_fdatasync(int __fd);
int			ft_fsync(int __fd);
char		*ft_getcwd(char *__buf, size_t __size);
gid_t		ft_getegid(void);
uid_t		ft_geteuid(void);
gid_t		ft_getgid(void);
int			ft_getgroups(int __count, gid_t __list[]);
int			ft_gethostname(char *__name, size_t __len);
pid_t		ft_getpgid(pid_t pid);
pid_t		ft_getpgrp(void);
pid_t		ft_getpid(void);
pid_t		ft_getppid(void);
pid_t		ft_getsid(pid_t __pid);
uid_t		ft_getuid(void);
int			ft_kill(pid_t __pid, int __sig);
int			ft_lchown(const char *__path, uid_t __uid, gid_t __gid);
int			ft_link(const char *__existing, const char *__new);
off_t		ft_lseek(int __fd, off_t __offset, int __whence);
int			ft_mkdir(const char *__path, mode_t __mode);
int			ft_pause(void);
int			ft_pipe(int __fd[2]);
int			ft_rmdir(const char *__path);
int			ft_symlink(const char *__existing, const char *__new);
void		ft_sync(void);
ssize_t		ft_write(int __fd, const void *__buf, size_t __size);
int			ft_open(const char *__path, int __flag, ...);
ssize_t		ft_read(int __fd, const void *__buf, size_t __size);
int			ft_close(int __fd);

#endif