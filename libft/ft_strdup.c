/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 01:15:39 by asbai-el          #+#    #+#             */
/*   Updated: 2019/12/24 11:53:57 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		size;
	int		i;
	char	*s2;

	if (s1 == NULL)
		return (NULL);
	s2 = (char*)s1;
	i = 0;
	size = ft_strlen(s1);
	if (!(cpy = (char*)malloc(size + 1)))
		return ((char*)0);
	ft_strlcpy(cpy, s2, size + 1);
	return (cpy);
}
