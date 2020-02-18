/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 22:01:26 by asbai-el          #+#    #+#             */
/*   Updated: 2019/11/04 18:53:07 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_start(const char *str, const char *set)
{
	int i;
	int j;
	int start;

	i = 0;
	start = 0;
	while (str[i])
	{
		j = 0;
		while (set[j])
		{
			if (str[i] == set[j])
			{
				start++;
				j = -5;
				break ;
			}
			j++;
		}
		if (j != -5)
			return (start);
		i++;
	}
	return (start);
}

static int			ft_end(const char *str, const char *set)
{
	int i;
	int j;
	int len;

	i = ft_strlen(str) - 1;
	len = 0;
	while (i >= 0)
	{
		j = 0;
		while (set[j])
		{
			if (str[i] == set[j])
			{
				len++;
				j = -5;
				break ;
			}
			j++;
		}
		if (j != -5)
			return (len + 1);
		i--;
	}
	return (len + 1);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	int		end;
	int		start;
	char	*clone;
	int		len;

	len = ft_strlen(s1);
	if (s1 == NULL || set == NULL)
		return (NULL);
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (!(clone = ft_substr(s1, start, (len - start) - end + 1)))
		return (ft_strdup(""));
	if (!(clone = ft_strdup(clone)))
		return (NULL);
	return (clone);
}
