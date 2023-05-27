/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboia-pe <rboia-pe@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 02:19:58 by rboia-pe          #+#    #+#             */
/*   Updated: 2023/04/07 02:19:58 by rboia-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}		t_list;

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_atoi(const char	*str);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_putchar(char c);
int				ft_putstr(char *str);

void			*ft_memset(void *ptr, int value, size_t num);
void			*ft_memcpy(void *dest, const void *src, size_t num);
void			*ft_memmove(void *dest, const void *src, size_t num);
void			*ft_memchr(const void *str, int d, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
void			ft_bzero(void *ptr, size_t num);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

size_t			ft_strlen(const char *str);
size_t			ft_strlcat(char *dest, const char *src, size_t d_size);
size_t			ft_strlcpy(char *dest, const char *src, size_t d_size);

char			*ft_strchr(const char *str, int d);
char			*ft_strrchr(const char *str, int d);
char			*ft_strnstr(const char *dest, const char *src, size_t len);
char			*ft_strdup(const char	*s);
char			*ft_substr(char const	*s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);

/*________________BONUS________________*/

t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *ls, void *(*f)(void *), void (*del)(void *));
t_list			*ft_lstnew(void *content);

int				ft_lstsize(t_list *lst);

void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));

/*_________________ADDTIONALS FUNCTIONS__________________*/

int			ft_putnbr_base(int nbr, char *base);

#endif
