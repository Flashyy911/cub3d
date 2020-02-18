/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 21:08:43 by asbai-el          #+#    #+#             */
/*   Updated: 2020/01/05 21:41:43 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_char_join(char *str, char c)
{
	char *new;

	new = malloc(sizeof(char) * (ft_strlen(str) + 1));
	ft_memcpy(new, str, ft_strlen(str));
	new[ft_strlen(str) + 1] = c;
	return (new);
}

char	*ft_char_join_free(char *str, char c)
{
	char *new;

	if (str == NULL)
	{
		new = malloc(sizeof(char) * 2);
		new[0] = c;
		new[1] = '\0';
	}
	else
	{
		new = malloc(sizeof(char) * (ft_strlen(str) + 1));
		ft_memcpy(new, str, ft_strlen(str));
		new[ft_strlen(str)] = c;
	}
	free(str);
	return (new);
}
