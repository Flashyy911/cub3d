/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 20:07:14 by asbai-el          #+#    #+#             */
/*   Updated: 2019/11/09 19:41:29 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(str = malloc((len + 1))))
		return (NULL);
	if (start < (unsigned int)ft_strlen(s))
		while (i < len && s[start + i])
		{
			str[i] = s[start + i];
			i++;
		}
	str[i] = '\0';
	return (str);
}
