/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mman.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:55:19 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/17 21:04:13 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MMAN_H

# define FT_MMAN_H

# include "ft_syscall.h"
# include "__vm.h"

# include <linux/limits.h>
# include <sys/types.h>
# include <sys/mman.h>
# include <limits.h>
# include <stdlib.h>
# include <stdint.h>
# include <errno.h>

# define UNIT	SYSCALL_MMAP2_UNIT

# ifndef MMAP2_PAGE_UNIT
#  define MMAP2_PAGE_UNIT	4096ULL
# endif

# ifndef PAGE_SIZE
#  define PAGE_SIZE	4096
# endif

# ifndef MREMAP_FIXED
#  define MREMAP_FIXED	2
# endif

#if MMAP2_PAGE_UNIT == -1ULL

# error "Page size check is unsupported."

#endif

/* Cuz norminette doesn't like over 4 args. */
typedef struct s_mmap_args
{
	void	*addr;
	size_t	len;
	int		prot;
	int		flags;
	int		fd;
	off_t	offset;
}	t_mmap_args;

/*
	Leave new_addr as NULL if you want
	to use old_addr as the new address
*/
typedef struct s_mremap_args
{
	void	*old_addr;
	void	*new_addr;
	size_t	old_len;
	size_t	new_len;
	int		flags;
}	t_mremap_args;

static __inline__ int	ft_munlockall(void)
{
	return (__syscall0(SYS_munlockall));
}

int		ft_madvise(void *addr, size_t len, int advice);
int		ft_mincore(void *addr, size_t len, unsigned char *vec);
int		ft_mlock(const void *addr, size_t len);
int		ft_mlockall(int flags);
void	*ft_mmap(t_mmap_args args);
int		ft_mprotect(void *addr, size_t len, int prot);
void	*ft_mremap(t_mremap_args args);
int		ft_msync(void *start, size_t len, int flags);
int		ft_munlock(const void *addr, size_t len);

#endif
