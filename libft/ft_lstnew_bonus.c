/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsnew_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 01:59:16 by asbai-el          #+#    #+#             */
/*   Updated: 2019/10/27 21:09:00 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *l1;

	if (!(l1 = malloc(sizeof(t_list))))
		return (NULL);
	l1->content = content;
	l1->next = NULL;
	return (l1);
}
