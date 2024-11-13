/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atexit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:45:21 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/13 17:54:19 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_misc.h"

static __always_inline t_exit_ctx	*__get_exit_context(void)
{
	static t_exit_ctx	ctx = {
		.head = &ctx.builtin,
		.builtin = { NULL, {NULL}, {NULL} },
		.finished = 0,
		.slot = 0
	};

	return (&ctx);
}

__attribute__((destructor)) void	__call_on_exit(void)
{
	t_exit_ctx	*ctx;
	void		(*fn)(void *);
	void		*arg;

	ctx = __get_exit_context();
	while (ctx->head)
	{
		ctx->slot = __at_exit_stack_handlers;
		while (ctx->slot-- > 0)
		{
			fn = ctx->head->f[ctx->slot];
			if (!fn)
				continue ;
			arg = ctx->head->a[ctx->slot];
			fn(arg);
		}
		ctx->head = ctx->head->next;
	}
	ctx->finished = 1;
}

/* 
	Multithreading safety: Not protected,
	assuming single-threaded context.
	Or external mutex lock.
*/
static int	__ft_cxa_atexit(void (*fn)(void *), void *arg)
{
	t_exit_ctx	*ctx;
	t_fl		*new_fl;

	if (!fn)
		return (-1);
	ctx = __get_exit_context();
	if (ctx->finished)
		return (-1);
	if (ctx->slot == __at_exit_stack_handlers)
	{
		new_fl = ft_calloc(sizeof(t_fl), 1);
		if (!new_fl)
			return (-1);
		new_fl->next = ctx->head;
		ctx->head = new_fl;
		ctx->slot = 0;
	}
	ctx->head->f[ctx->slot] = fn;
	ctx->head->a[ctx->slot] = arg;
	++ctx->slot;
	return (0);
}

extern int	ft_atexit(void (*fn)(void *), void *arg)
			__attribute__((weak, alias("__ft_cxa_atexit")));
