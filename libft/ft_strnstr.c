/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 21:18:03 by asbai-el          #+#    #+#             */
/*   Updated: 2019/11/06 16:24:19 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	int		little_size;
	char	*big2;

	big2 = (char*)big;
	if (!big && len == 0)
		return (0);
	little_size = ft_strlen(little);
	i = 0;
	if (little[0] == '\0')
		return (big2);
	if (!big2)
		len = 1000;
	while (i <= (int)len - little_size)
	{
		if (ft_strncmp(big2 + i, little, little_size) == 0)
			return (big2 + i);
		i++;
	}
	return (0);
}
