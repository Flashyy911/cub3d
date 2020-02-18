/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_t_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 11:53:57 by asbai-el          #+#    #+#             */
/*   Updated: 2019/12/24 11:55:49 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_calculate(char *nbr, size_t n, int i)
{
	size_t res;

	i--;
	nbr[i + 1] = '\0';
	while (i >= 0)
	{
		res = n % 10;
		n = n / 10;
		nbr[i] = (int)res + '0';
		i--;
	}
	return (nbr);
}

static char		*ft_allocstr(char *str, size_t n)
{
	int				i;
	size_t			nbr;
	size_t			clone;

	nbr = n;
	clone = nbr;
	i = 0;
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	if (!(str = malloc(i + 1)))
		return (NULL);
	ft_calculate(str, clone, i);
	return (str);
}

static char		*ft_zerocase(char *str)
{
	if (!(str = malloc(2)))
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char			*ft_size_t_itoa(size_t n)
{
	char *str;

	str = "";
	if (n == 0)
		str = ft_zerocase(str);
	else
		str = ft_allocstr(str, n);
	return (str);
}
