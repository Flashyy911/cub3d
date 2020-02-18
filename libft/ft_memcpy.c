/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 22:13:28 by asbai-el          #+#    #+#             */
/*   Updated: 2019/11/09 19:48:21 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*src1;
	unsigned char	*dst1;

	if (dst == 0 && src == 0)
		return (0);
	src1 = (unsigned char*)src;
	dst1 = (unsigned char*)dst;
	if (ft_memcmp(dst1, src1, n) == 0)
		return (dst);
	i = 0;
	while (i < n)
	{
		dst1[i] = src1[i];
		i++;
	}
	return (dst);
}
