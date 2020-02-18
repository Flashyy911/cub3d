/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 09:24:24 by asbai-el          #+#    #+#             */
/*   Updated: 2020/01/17 14:05:16 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 1
int		get_next_line(int fd, char **line);
size_t 	ft_strlen(const char *str);
char	*ft_strcharjoin(char **line, char const *file_content, int *n);
void	*ft_strndecal(char **str, int *n);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t c);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
#endif
