/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 00:02:19 by asbai-el          #+#    #+#             */
/*   Updated: 2019/10/27 21:03:38 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*obj;

	if (!(obj = malloc(count * size)))
		return ((void*)0);
	ft_bzero(obj, count * size);
	return ((void*)obj);
}
