/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 02:15:44 by asbai-el          #+#    #+#             */
/*   Updated: 2019/10/27 22:26:39 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_calculate(char *nbr, long n, int isneg, int i)
{
	int res;
	int test;

	if (isneg == 1)
	{
		nbr[0] = '-';
		test = 1;
	}
	else
	{
		test = 0;
		i--;
	}
	nbr[i + 1] = '\0';
	while (i >= test)
	{
		res = n % 10;
		n = n / 10;
		nbr[i] = (int)res + '0';
		i--;
	}
	return (nbr);
}

static char		*ft_allocstr(char *str, int n)
{
	int				i;
	int				isneg;
	long			nbr;
	long			clone;

	isneg = n < 0;
	nbr = n;
	nbr = nbr > 0 ? nbr : -nbr;
	clone = nbr;
	i = 0;
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	if (!(str = malloc(i + 1 + isneg)))
		return (NULL);
	ft_calculate(str, clone, isneg, i);
	return (str);
}

static char		*ft_zerocase(char *str1)
{
	if (!(str1 = malloc(2)))
		return (NULL);
	str1[0] = '0';
	str1[1] = '\0';
	return (str1);
}

char			*ft_itoa(int n)
{
	char *str1;

	str1 = "";
	if (n == 0)
		str1 = ft_zerocase(str1);
	else
		str1 = ft_allocstr(str1, n);
	return (str1);
}
