/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 09:30:37 by asbai-el          #+#    #+#             */
/*   Updated: 2020/01/17 12:04:37 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

size_t 			ft_strlen(const char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char		*ft_strcharjoin(char **line, char const *file_content, int *n)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = malloc(ft_strlen(*line) + ft_strlen(file_content) + 1)))
		return (0);
	if (*line)
	{
		while ((*line)[i])
		{
			str[i] = (*line)[i];
			i++;
		}
		while (file_content[*n] && file_content[*n] != '\n')
		{
			str[i] = file_content[*(n)];
			i++;
			*(n) = *(n) + 1;
		}
	}
	str[i] = '\0';
	free(*line);
	return (str);
}

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*src1;
	unsigned char	*dst1;
	size_t			i;

	src1 = (unsigned char*)src;
	dst1 = (unsigned char*)dst;
	i = 0;
	while (i < n)
	{
		dst1[i] = src1[i];
		if (src1[i] == (unsigned char)c)
			dst1[i] = src1[i];
		i++;
	}
	return (dst1);
}

char		*ft_strdup(const char *s1)
{
	char	*cpy;
	int		size;
	int		i;
	char	*s2;

	s2 = (char*)s1;
	i = 0;
	size = ft_strlen(s1);
	if (s1 == NULL)
		return (0);
	if (!(cpy = (char*)malloc(size + 1)))
		return ((char*)0);
	ft_strlcpy(cpy, s2, size + 1);
	return (cpy);
}

size_t		ft_strlcpy(char *dst, const char *src, size_t c)
{
	int i;

	if (!dst || !src)
		return (0);
	i = 0;
	while (i < (int)c - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (c > 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}
