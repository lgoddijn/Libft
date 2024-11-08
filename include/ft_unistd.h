/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unistd.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:01:20 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/08/26 18:54:50 by lgoddijn         ###   ########.fr       */
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
# include <fcntl.h>

# include "ft_syscall.h"
# include "ft_values.h"

int32_t			ft_access(const char *__path, int32_t __mode);
uint32_t		ft_alarm(uint32_t seconds);
int32_t			ft_chmod(const char *__path, mode_t __mode);
int32_t			ft_chown(const char *__path, uid_t __uid, gid_t __gid);
int32_t			ft_chdir(const char *__path);
int32_t			ft_dup(int32_t __fd);
int32_t			ft_dup2(int32_t __old, int32_t __new);
int32_t			ft_execve(
					const char *__path,
					char *const __argv[],
					char *const __envp[]);
_Noreturn void	ft_exit_group(int32_t __status);
_Noreturn void	ft_exit(int32_t __status);
int32_t			ft_fchdir(int32_t __fd);
int32_t			ft_fchown(int32_t __fd, uid_t __uid, gid_t __gid);
int32_t			ft_fdatasync(int32_t __fd);
int32_t			ft_fsync(int32_t __fd);
char			*ft_getcwd(char *__buf, size_t __size);
gid_t			ft_getegid(void);
uid_t			ft_geteuid(void);
gid_t			ft_getgid(void);
int32_t			ft_getgroups(int32_t __count, gid_t __list[]);
int32_t			ft_gethostname(char *__name, size_t __len);
pid_t			ft_getpgid(pid_t pid);
pid_t			ft_getpgrp(void);
pid_t			ft_getpid(void);
pid_t			ft_getppid(void);
pid_t			ft_getsid(pid_t __pid);
pid_t			ft_gettid(void);
uid_t			ft_getuid(void);
int32_t			ft_lchown(
					const char *__path,
					uid_t __uid,
					gid_t __gid);
int32_t			ft_link(const char *__existing, const char *__new);
off_t			ft_lseek(int32_t __fd, off_t __offset, int32_t __whence);
int32_t			ft_mkdir(const char *__path, mode_t __mode);
int32_t			ft_pause(void);
int32_t			ft_pipe(int32_t __fd[2]);
int32_t			ft_rmdir(const char *__path);
int32_t			ft_symlink(const char *__existing, const char *__new);
void			ft_sync(void);
ssize_t			ft_write(int32_t __fd, const void *__buf, size_t __size);
int32_t			ft_open(const char *__path, int32_t __flag, ...);
ssize_t			ft_read(int32_t __fd, const void *__buf, size_t __size);
int32_t			ft_close(int32_t __fd);
pid_t			ft_waitpid(pid_t __pid, int32_t *__status, int32_t __options);
pid_t			ft_wait(int32_t *__status);
ssize_t			ft_readlink(
					const char *path,
					char *buf,
					size_t size);

#endif
