/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 02:44:49 by asbai-el          #+#    #+#             */
/*   Updated: 2019/11/08 16:59:06 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	tmp = *alst;
	if (!*alst)
	{
		*alst = new;
	}
	else
	{
		while ((tmp)->next)
		{
			(tmp) = (tmp)->next;
		}
		(tmp)->next = new;
	}
}
