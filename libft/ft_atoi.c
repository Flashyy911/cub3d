/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 23:37:52 by asbai-el          #+#    #+#             */
/*   Updated: 2019/11/04 18:31:31 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_atoi(const char *str)
{
	unsigned int	nbr;
	int				mult;
	int				i;
	int				sign;

	mult = 1;
	nbr = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		i++;
		sign = -1;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) == 1 && str[i])
	{
		nbr = (nbr * 10) + ((int)(str[i]) - 48);
		i++;
	}
	return (nbr * sign);
}
