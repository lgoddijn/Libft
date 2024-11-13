/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:14:59 by lgoddijn          #+#    #+#             */
/*   Updated: 2024/11/13 17:19:55 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	test_setenv(char **envp)
{
	ft_setenvp("TESTABC", "ABC", 1, &envp);

	if (!ft_getenvp("TESTABC", envp))
		printf("FAILED\n");
	else
		printf("PASSED\n");
}

int main(int argc, char **av, char **envp)
{
	test_setenv(envp);
	return (0);
}
