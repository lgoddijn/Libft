/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:48:52 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/08/20 15:53:22 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RESOLVE_H

# define FT_RESOLVE_H

# include "ft_string.h"
# include "ft_memory.h"
# include "ft_unistd.h"
# include "ft_env.h"

char	*ft_realpath(const char *__restrict__ path, char resolved[PATH_MAX]);

#endif
