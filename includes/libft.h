/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:49:59 by asbai-el          #+#    #+#             */
/*   Updated: 2020/01/05 21:40:46 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

typedef	struct			s_list
{
	void				*content;
	struct s_list		*next;
}						t_list;
char					*ft_char_join(char *str, char c);
char					*ft_char_join_free(char *str, char c);
char					*ft_strdupfree(char *str_free, char *new);
char					*ft_size_t_itoa(size_t n);
char					*ft_strjoinfree(char *s1, char *s2);
int						ft_strchrn(const char *str, char chr);
void					ft_putnbr(int nb);
void					ft_putchar(char c);
void					ft_putnbr_fd(int n, int fd);
void					ft_putstr_fd(char *s, int fd);
void					ft_putchar_fd(char c, int fd);
char					*ft_strmapi(char const *s,
									char (*f)(unsigned int, char));
char					*ft_itoa(int n);
char					**ft_split(char const *s, char c);
char					*ft_removeright(char *str, char *set);
char					*ft_removeleft(char *str, char *set);
char					*ft_strtrim(char const *s1, char const *set);
char					**ft_split(char const *s, char c);
char					*ft_substr(char const *s,
									unsigned int start, size_t len);
int						*ft_isspace(int c);
char					*ft_strdup(const char *s1);
void					*ft_calloc(size_t count, size_t size);
int						ft_atoi(const char *str);
int						ft_toupper(int c);
int						ft_tolower(int c);
int						ft_strncmp(const char *str1,
									const char *str2, size_t n);
char					*ft_strchr(const char *str, int c);
char					*ft_strrchr(const char *str, int c);
size_t					ft_strlcpy(char *dst, const char *src, size_t c);
void					*ft_memset(void *str, int c, size_t len);
void					ft_bzero(void *str, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memccpy(void *dst, const void *src,
									int c, size_t t);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memchr(const void *str, int c, size_t n);
int						ft_memcmp(const void *str1, const void *str2, size_t n);
size_t					ft_strlen(const char *str);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
size_t					ft_strlcat(char *dst, char *src, size_t c);
char					*ft_strnstr(const char *big, const char *little,
						size_t len);
int						ft_strcmp(char *s1, char *s2);
char					*ft_strjoin(char const *s1, char const *s2);
void					ft_putendl_fd(char *s, int fd);
void					ft_lstclear(t_list **lst, void (*del)(void *));
void					ft_lstadd_back(t_list **alst, t_list *new);
t_list					*ft_lstnew(void	*content);
void					ft_lstadd_front(t_list **alst, t_list *new);
int						ft_lstsize(t_list	*lst);
t_list					*ft_lstlast(t_list	*lst);
void					ft_lstdelone(t_list	*lst, void (*del)(void	*));
void					ft_lstiter(t_list	*lst, void (*f)(void *));
t_list					*ft_lstmap(t_list *lst,
									void *(*f)(void *), void (*del)(void *));
#endif
