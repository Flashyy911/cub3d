/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:04:54 by asbai-el          #+#    #+#             */
/*   Updated: 2019/11/09 19:37:04 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*str1_clone;
	unsigned char	*str2_clone;

	i = 0;
	str1_clone = (unsigned char*)str1;
	str2_clone = (unsigned char*)str2;
	while (i < n)
	{
		if (str1_clone[i] != str2_clone[i])
			return (str1_clone[i] - str2_clone[i]);
		i++;
	}
	return (0);
}
