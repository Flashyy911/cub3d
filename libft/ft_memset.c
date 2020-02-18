/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:04:30 by asbai-el          #+#    #+#             */
/*   Updated: 2019/11/09 19:48:10 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str2 = (unsigned char*)str;
	while (i < len)
	{
		str2[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
