/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:10:03 by asbai-el          #+#    #+#             */
/*   Updated: 2019/11/09 19:37:21 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst1;
	char			*src1;

	dst1 = dst;
	src1 = (char*)src;
	if (!len || src == dst)
		return (dst);
	if (dst > src)
		while (len--)
			dst1[len] = src1[len];
	else
		while (len--)
			*dst1++ = *src1++;
	return (dst);
}
