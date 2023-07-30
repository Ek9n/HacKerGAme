/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sung-hle <sung-hle@42student.berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:21:13 by sung-hle          #+#    #+#             */
/*   Updated: 2023/03/23 17:57:07 by sung-hle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
void	*ft_calloc(size_t num, size_t size);
int		ft_isalpha(int arg);
int		ft_isdigit(int arg);
int		ft_isalnum(int arg);
int		ft_isascii(int c);
int		ft_isprint(int arg);
char	*ft_itoa(int n);
int		ft_toupper(int chr);
int		ft_tolower(int chr);
int		ft_strncmp(const char *st1, const char *st2, size_t n);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *target, int value, size_t size);
void	*ft_memcpy(void *target, void const *source, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(void const *first, void const *second, size_t size);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *big, const char *little, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_atoi(const char *bumms);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *src);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_itoa(int n);
int		ft_printf(const char *str, ...);
int		ft_putchar_fd_printf(char c, int fd);
int		ft_putnbr_base_fd(unsigned long long nb, char *base, int fd, int *ctr);
int		ft_putnbr_ui_fd_printf(unsigned int nb, int fd, int *counter);
int		ft_putnbr_fd_printf(int nb, int fd, int *counter);
int		ft_putstr_printf_fd(char *s, int fd);
int		ft_voidcase(long long int vptr, char *s, int fd, int *counter);
// void	ft_error(char *str);
size_t	ft_gnllcpy(char *dst, const char *src, size_t size);
char	*ft_freebuf(char **buf);
size_t	ft_gnllen(const char *str);
void	*ft_calloc_gnl(size_t size);
char	*get_next_line(int fd);
#endif
