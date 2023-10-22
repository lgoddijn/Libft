/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:48:53 by lgoddijn          #+#    #+#             */
/*   Updated: 2023/10/19 17:11:42 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>

/*

@make
	The make file contains all mandatory functions in the `all` rule.
	The bonus functions are contained under the `bonus` rule.
	The extra functions will be contained under the `extra` rule.
	All functions will have their own respective category and
	`all` will be used to compile them all, due to the subject not right now.

	Ex.
		`make fclean all`, `make fclean bonus`, `make fclean extra`;

@notes
	For documentation go to the respective `*.c` file
	Each function has its own `*.c` file named after it.

	Extra functions are defined in the respective parent function's `*.c` file.
	They will always be defined as `static` to maintain the scope within that file.

	Prototypes are split by usage cases.

	New functions will be added as time goes on.

	All new typedefs will be stored in this header file.

	All constants will be defined as `macro` (ex. #define KEPSILON 1E-05f).

*/

/*
----------------------------------
		Constants & Macros
----------------------------------
*/

// When you can't return NULL or -1
// This is just an int bool ig
// This works for both long and int

# define C_0K_LMA0 0xC0FFEE
# define K0_C_LMA0 -0xDEAD

/*
-----------------------------------
		String IS Functions
-----------------------------------
*/

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

/*
-----------------------------------
		String TO Functions
-----------------------------------
*/

int		ft_toupper(int c);
int		ft_tolower(int c);

/*
------------------------------------
		Allocation Functions
------------------------------------
*/

void	*ft_calloc(size_t nmemb, size_t size);

/*
--------------------------------
		Memory Functions
--------------------------------
*/

void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);

/*
--------------------------------
		String Functions
--------------------------------
*/

size_t	ft_strlen(const char *s);
int		ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/*
-----------------------------------------
		File Descriptor Functions
-----------------------------------------
*/

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/*
-------------------------------------
		Linked List Functions
-------------------------------------
*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif // LIBFT_H