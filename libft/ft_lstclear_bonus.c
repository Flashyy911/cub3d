/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 03:48:35 by asbai-el          #+#    #+#             */
/*   Updated: 2019/10/27 19:12:30 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;

	tmp = *lst;
	while ((*lst)->next)
	{
		tmp = (*lst);
		*lst = (*lst)->next;
		del(tmp->content);
		free(tmp);
	}
	del((*lst)->content);
	free((*lst));
	*lst = NULL;
}
