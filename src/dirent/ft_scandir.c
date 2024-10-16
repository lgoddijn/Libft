/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scandir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 00:32:55 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/10/16 15:48:19 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_dirent.h"

static __inline__ void	__do_loop(
		t_scandir_args *args,
		t_scandir_locale *loc,
		t_dir **d)
{
	while (loc->de)
	{
		errno = 0;
		if (args->sel && !args->sel(loc->de))
		{
			loc->de = ft_readdir(*d);
			continue ;
		}
		if (loc->cnt >= loc->len)
		{
			loc->len = 2 * loc->len + 1;
			if (loc->len > SIZE_MAX / sizeof(*loc->names))
				break ;
			loc->tmp = (struct dirent **)ft_realloc(
					loc->names, loc->len * sizeof(*loc->names));
			if (!loc->tmp)
				break ;
			loc->names = loc->tmp;
		}
		loc->names[loc->cnt] = (struct dirent *)malloc((loc->de)->d_reclen);
		if (!loc->names[loc->cnt])
			break ;
		ft_memcpy(loc->names[loc->cnt++], loc->de, (loc->de)->d_reclen);
		loc->de = ft_readdir(*d);
	}
}

int	ft_scandir(t_scandir_args *args)
{
	t_scandir_locale	loc;
	t_dir				*d;

	d = ft_opendir(args->path);
	loc.oerrno = errno;
	loc.names = 0;
	loc.cnt = 0;
	loc.len = 0;
	if (!d)
		return (-1);
	loc.de = ft_readdir(d);
	__do_loop(args, &loc, &d);
	ft_closedir(d);
	if (errno)
	{
		while (loc.names && loc.cnt-- > 0)
			free((void *)loc.names[loc.cnt]);
		return (free((void *)loc.names), -1);
	}
	errno = loc.oerrno;
	if (args->cmp)
		ft_srt_cmp(loc.names, loc.cnt, sizeof(*(loc.names)),
			(int (*)(const void *, const void *))args->cmp);
	*(args->res) = loc.names;
	return (loc.cnt);
}
