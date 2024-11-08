/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frpath.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:35:49 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/07 18:37:37 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_misc.h"

static __inline__ size_t	slash_count(const char *__restrict__ s)
{
	const char	*s0 = s;

	while (*s == '/')
		++s;
	return (s - s0);
}

static __inline__ t_loc	*__init(const char *__restrict__ path, t_loc *lc)
{
	*lc.nparent = 0;
	*lc.check_directory = 0;
	if (!path)
	{
		errno = EINVAL;
		return (NULL);
	}
	*lc.l = ft_strnlen(path, sizeof(*lc.stk));
	if (!*lc.l)
	{
		errno = ENOENT;
		return (NULL);
	}
	if (*lc.l >= PATH_MAX)
	{
		errno = ENAMETOOLONG;
		return (NULL);
	}
	*lc.p = sizeof(*lc.stk) - *lc.l - 1;
	*lc.q = 0;
	ft_memcpy(*lc.stk + *lc.p, path, *lc.l + 1);
	return (lc);
}

static __inline__ t_loc	*__do_readlink(t_loc *lc)
{
	if (lc.do_readlink)
	{
		lc.k = readlink(lc.out, lc.stk, lc.p);
		if (!lc.k)
		{
			errno = ENOENT;
			return (NULL);
		}
		if ((size_t)lc.k == lc.p)
		{
			errno = ENAMETOOLONG;
			return (NULL);
		}
		if (lc.k == -1 && errno != EINVAL)
			return (NULL);
		if (lc.k > 0)
		{
			if (lc.stk[lc.k - 1] == '/')
				while (lc.stk[lc.p] == '/')
					++lc.p;
			lc.p -= lc.k;
			ft_memmove((void *)(lc.stk + lc.p), (const void *)lc.stk, lc.k);
			continue ;
		}
	}
	return (lc);
}

static __inline__ t_loc	*__do_absolute(t_loc *lc)
{
	if (lc.stk[lc.p] == '~')
	{
		errno = ENOENT;
		return (NULL);
	}
	if (lc.stk[lc.p] == '/')
	{
		lc.check_directory = 0;
		lc.nparent = 0;
		lc.q = 0;
		lc.out[lc.q++] = '/';
		++lc.p;
		if (lc.stk[lc.p] == '/' && lc.stk[lc.p + 1] != '/')
			lc.out[q++] = '/';
		lc.p += slash_count(lc.stk + lc.p);
		continue ;
	}
	lc.l = ft_strcspn(lc.stk + lc.p, "/");
	lc.l0 = lc.l;
	if (!lc.l && !lc.check_directory)
		break ;
	return (lc);
}

static __inline__ t_loc	*__loop()
{
	while (1)
	{
		__do_absolute();
		if (lc.l == 1 && lc.stk[lc.p] == '.')
		{
			lc.p += lc.l + slash_count(lc.stk + lc.p + lc.l);
			continue ;
		}
		if (lc.q && lc.out[lc.q - 1] != '/')
		{
			if (!lc.p)
			{
				errno = ENAMETOOLONG;
				return (NULL);
			}
			lc.stk[--lc.p] = '/';
			++lc.l;
		}
		if (lc.q + lc.l >= PATH_MAX)
		{
			errno = ENAMETOOLONG;
			return (NULL);
		}
		ft_memcpy((char *)lc.out + lc.q, (const char *)lc.stk + lc.p, lc.l);
		lc.out[lc.q + lc.l] = '\0';
		lc.p += lc.l;
		lc.parent = (lc.l0 == 2 && lc.stk[lc.p - 2] == '.' && lc.stk[lc.p - 1] == '.');
		lc.do_readlink = !lc.parent;
		if (lc.parent)
		{
			if (lc.q <= 3 * lc.nparent)
			{
				++lc.nparent;
				lc.q += lc.l;
				lc.p += slash_count(lc.stk + lc.p);
				continue ;
			}
		}
		__do_readlink();
		if (lc.parent)
		{
			while (lc.q && lc.out[lc.q - 1] != '/')
				--lc.q;
			if (lc.q > 1 && (lc.q > 2 || lc.out[0] != '/'))
				--lc.q;
			lc.p += slash_count(lc.stk + lc.p);
			continue ;
		}
		if (lc.l0)
			lc.q += lc.l;
		lc.check_directory = lc.stk[lc.p];
		lc.p += slash_count(lc.stk + lc.p);
		continue ;
	}
}

char	*frpath(const char *__restrict__ path, char resolved[PATH_MAX])
{
	t_loc	lc;

	if (!__init(path, &lc))
		return (NULL);
	__loop();
	lc.out[lc.q] = '\0';
	if (lc.out[0] != '/')
	{
		if (!ft_getcwd(lc.stk, sizeof(lc.stk)))
			return (NULL);
		lc.l = ft_strlen(lc.stk);
		lc.p = 0;
		while (lc.nparent--)
		{
			while(lc.l > 1 && lc.stk[lc.l - 1] != '/')
				--lc.l;
			if (lc.l > 1)
				--lc.l;
			lc.p += 2;
			if (lc.p < lc.q)
				++lc.p;
		}
		if (lc.q - lc.p && lc.stk[lc.l - 1] != '/')
			lc.stk[lc.l++] = '/';
		if (lc.l + (lc.q - lc.p) + 1 >= PATH_MAX)
		{
			errno = ENAMETOOLONG;
			return (NULL);
		}
		ft_memmove((void *)(lc.out + lc.l), (const void *)(lc.out + lc.p), lc.q - lc.p + 1);
		ft_memcpy((void *)lc.out, (const void *)lc.stk, lc.l);
		lc.q = lc.l + lc.q - lc.p;
	}
	return (ft_memcpy(resolved, lc.out, lc.q + 1));
}

char	*frpath(const char *__restrict__ path, char resolved[PATH_MAX])
{
	char	stk[PATH_MAX + 1];
	char	out[PATH_MAX];

	size_t	p;
	size_t	q;

	ssize_t	k;

	size_t	l;
	size_t	l0;

	int32_t	parent;

	int32_t	do_readlink;

	size_t	nparent = 0;

	int32_t	check_directory = 0;

	if (!path)
	{
		errno = EINVAL;
		return (NULL);
	}

	/* Input length */

	l = ft_strnlen(path, sizeof(stk));

	if (l == 0)
	{
		errno = ENOENT;
		return (NULL);
	}

	if (l >= PATH_MAX)
	{
		errno = ENAMETOOLONG;
		return (NULL);
	}

	/* Work backwards */

	p = sizeof(stk) - l - 1;

	q = 0;

	ft_memcpy((void *)(stk + p), (const void *)path, l + 1);

	/*
		Main loop. Each iteration pops the next part from stk of
		remaining path components and consumes any slashes that follow.
		If not a link, it's moved to out; if a link, contents are
		pushed to the stk.
	*/

	while (1)
	{
		if (stk[p] == '~')
		{
			errno = ENOENT;
			return (NULL);
		}

		if (stk[p] == '/')
		{
			/* Handle absolute path */

			check_directory = 0;

			nparent = 0;
			q = 0;

			out[q++] = '/';

			++p;

			/* Initial `//` is special. */

			if (stk[p] == '/' && stk[p + 1] != '/')
				out[q++] = '/';

			p += slash_count(stk + p);

			continue ;
		}

		/* Find first `/` and get the length up to it
		 * (Length of first component) */

		l = ft_strcspn(stk + p, "/");

		l0 = l;

		if (!l && !check_directory) break ;

		/* Skip any `.` component but preserve check_directory status. */

		if (l == 1 && stk[p] == '.')
		{
			p += l + slash_count(stk + p + l);
			continue ;
		}

		/* Copy next component onto out at least temporarily, to
		 * call readlink, but wait to advance out position until
		 * determining it's not a link. */

		if (q && out[q - 1] != '/')
		{
			if (!p)
			{
				errno = ENAMETOOLONG;
				return (NULL);
			}

			stk[--p] = '/';
			++l;
		}

		if (q + l >= PATH_MAX)
		{
			errno = ENAMETOOLONG;
			return (NULL);
		}

		ft_memcpy((char *)out + q, (const char *)stk + p, l);

		out[q + l] = '\0';

		p += l;

		/* By default not parent and do readlink */

		parent = (l0 == 2 && stk[p - 2] == '.' && stk[p - 1] == '.');

		/* When previous components are already known to be
		 * directories, processing `..` can skip readlink. */

		do_readlink = !parent;

		if (parent)
		{
			/* Any non `..` path components we could cancel start
			 * after nparent repetitions of the 3-byte string "../";
			 * if there are none, accumulate `..` components to
			 * later apply to cwd, if needed. */

			if (q <= 3 * nparent)
			{
				++nparent;
				q += l;
				p += slash_count(stk + p);
				continue ;
			}
		}

		if (do_readlink)
		{
			/* Get component from out, resolve into stk */

			k = readlink(out, stk, p);

			/* Check for errors other than file isnt symlink
			 * and check that 0 bytes are written or
			 * k bytes overflow to stk position */

			if (!k)
			{
				errno = ENOENT;
				return (NULL);
			}

			if ((size_t)k == p)
			{
				errno = ENAMETOOLONG;
				return (NULL);
			}

			if (k == -1 && errno != EINVAL)
				return (NULL);

			if (k > 0)
			{
				/* Strip any slashes in symlink to
				* avoid double slashes later */

				if (stk[k - 1] == '/')
					while (stk[p] == '/') ++p;

				/* Offset position by length of symlink */

				p -= k;

				/* Shift the stk and update content with symlink */

				ft_memmove((void *)(stk + p), (const void *)stk, k);

				/* Skip the stk advancement in case
				* we have a new absolute base path. */

				continue ;
			}
		}

		if (parent)
		{
			/* If parent directory, backtrack to previous
			 * slash character ensuring no segfaults */

			while (q && out[q - 1] != '/') --q;
			if (q > 1 && (q > 2 || out[0] != '/')) --q;

			p += slash_count(stk + p);

			continue ;
		}

		/* If there was a length to the first `/`
		 * originally, offset out position */

		if (l0)
			q += l;

		/* Any non \0 character */

		check_directory = stk[p];

		p += slash_count(stk + p);
		continue ;
	}

	out[q] = '\0';

	/* Check if path is absolute */

	if (out[0] != '/')
	{
		if (!ft_getcwd(stk, sizeof(stk)))
			return (NULL);

		/* Only cwd is in stk */

		l = ft_strlen(stk);

		/* Cancel any initial `..` components. */

		p = 0;

		while (nparent--)
		{
			while(l > 1 && stk[l - 1] != '/') --l;

			if (l > 1) --l;

			p += 2;

			if (p < q) ++p;
		}

		/* Add initial slash to make absolute */

		if (q - p && stk[l - 1] != '/')
			stk[l++] = '/';

		if (l + (q - p) + 1 >= PATH_MAX)
		{
			errno = ENAMETOOLONG;
			return (NULL);
		}

		ft_memmove((void *)(out + l), (const void *)(out + p), q - p + 1);
		ft_memcpy((void *)out, (const void *)stk, l);

		q = l + q - p;
	}

	return (ft_memcpy(resolved, out, q + 1));
}
