/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:31:33 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/04/14 19:16:04 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEAP_H

# define FT_HEAP_H

# include <sys/mman.h>
# include <sys/syscall.h>
# include <sys/sysinfo.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>

# include "ft_values.h"
# include "ft_internal.h"
# include "ft_memory.h"

void	*ft_mmap(
			size_t __size,
			int32_t __prot,
			int32_t __flags,
			off_t __offset
			);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_realloc(void *ptr, size_t size);
void	ft_free2d(void **ptr);

#endif
