/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:56:26 by asbai-el          #+#    #+#             */
/*   Updated: 2019/11/09 19:48:03 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*str1;

	i = n;
	str1 = (unsigned char*)str;
	while (i--)
	{
		if (*str1 == (unsigned char)c)
			return (str1);
		str1++;
	}
	return (NULL);
}
