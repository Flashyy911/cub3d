/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 03:46:50 by asbai-el          #+#    #+#             */
/*   Updated: 2020/01/02 19:17:54 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str1;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(str1 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (0);
	while (s1[i])
	{
		str1[i] = s1[i];
		i++;
	}
	j = i;
	i = 0;
	while (s2[i])
		str1[j++] = s2[i++];
	str1[j] = '\0';
	free(s1);
	free(s2);
	return (str1);
}
