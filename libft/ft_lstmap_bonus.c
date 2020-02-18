/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 03:30:55 by asbai-el          #+#    #+#             */
/*   Updated: 2019/11/01 12:52:24 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*tmp;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	lst2 = NULL;
	while (lst)
	{
		if ((tmp = ft_lstnew((*f)(lst->content))) == NULL)
		{
			ft_lstclear(&tmp, del);
			return (NULL);
		}
		ft_lstadd_back(&lst2, tmp);
		lst = lst->next;
	}
	return (lst2);
}
