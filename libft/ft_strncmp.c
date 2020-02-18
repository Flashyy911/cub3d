/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:41:34 by asbai-el          #+#    #+#             */
/*   Updated: 2019/11/09 20:24:00 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*str1_clone;
	unsigned char	*str2_clone;

	i = 0;
	str1_clone = (unsigned char*)str1;
	str2_clone = (unsigned char*)str2;
	while (i < n)
	{
		if (str1_clone[i] == '\0' || str2_clone[i] == '\0')
			return (str1_clone[i] - str2_clone[i]);
		if (str1_clone[i] != str2_clone[i])
			return (str1_clone[i] - str2_clone[i]);
		i++;
	}
	return (0);
}
