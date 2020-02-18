/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 12:23:54 by asbai-el          #+#    #+#             */
/*   Updated: 2019/11/06 16:19:32 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t c)
{
	int dst_len;
	int size;
	int i;

	i = 0;
	if (src && !dst && c == 0)
		return (ft_strlen(src));
	if ((!dst && c == (int)0))
		return (0);
	dst_len = ft_strlen(dst);
	if ((int)c <= dst_len)
		size = ft_strlen(src) + (int)c;
	else
		size = ft_strlen(src) + dst_len;
	while (src[i] && dst_len + 1 < (int)c)
		dst[dst_len++] = src[i++];
	if (dst[dst_len] != '\0')
		dst[dst_len] = '\0';
	return ((size_t)size);
}
