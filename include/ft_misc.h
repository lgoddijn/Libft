/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:35:59 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/11 21:10:26 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MISC_H

# define FT_MISC_H

# include "ft_memory.h"
# include "ft_string.h"
# include "ft_unistd.h"

# include <linux/limits.h>

# include "../src/misc/frpath/__frpath.h"

char	*frpath(const char *__restrict__ path, char resolved[PATH_MAX]);

#endif
