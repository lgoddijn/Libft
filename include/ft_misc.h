/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:35:59 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/07 18:14:11 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MISC_H

# define FT_MISC_H

# include "ft_memory.h"
# include "ft_string.h"
# include "ft_unistd.h"

typedef struct s_loc
{
	char	stk[PATH_MAX + 1];
	char	out[PATH_MAX];
	size_t	p;
	size_t	q;
	ssize_t	k;
	size_t	l;
	size_t	l0;
	int		parent;
	size_t	nparent;
	int		do_readlink;
	int		check_directory;
}	t_loc;

#endif
