/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:33:54 by asbai-el          #+#    #+#             */
/*   Updated: 2019/11/04 18:49:01 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static void				ft_clear(char **tab, int size)
{
	int i;

	i = 0;
	if (size < 0)
		while (i <= size)
			free(tab[i++]);
	free(tab);
}

static	int				ft_tabsize(char const *s, int c)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			len++;
		i++;
	}
	if (len == 0 && s[0] != c && s[0])
		len++;
	return (len);
}

static char				**ft_taballoc(char const *s, int tab_size)
{
	int		i;
	int		j;
	int		s_len;
	char	**tab;

	i = 0;
	j = 0;
	s_len = ft_strlen(s);
	if (!(tab = malloc(sizeof(char*) * tab_size + 1)))
	{
		ft_clear(tab, 0);
		return (NULL);
	}
	tab[tab_size + 1] = 0;
	while (i <= tab_size)
	{
		if (!(tab[i] = malloc(s_len + 1)))
		{
			ft_clear(tab, i);
			return (NULL);
		}
		i++;
	}
	return (tab);
}

static void				ft_fill(char const *s, int c, char **tab)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
		if (s[i] == c)
		{
			if (s[i - 1] != c && i > 0)
				tab[j++][k] = '\0';
			while (s[i + 1] == c)
				i++;
			i++;
			k = 0;
		}
		else
			tab[j][k++] = s[i++];
}

char					**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	if (s == NULL)
		return (NULL);
	k = 0;
	j = 0;
	i = 0;
	if (!(tab = ft_taballoc(s, ft_tabsize(s, c))))
	{
		return (NULL);
	}
	ft_fill(s, c, tab);
	tab[ft_tabsize(s, c)] = NULL;
	return (tab);
}
