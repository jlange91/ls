/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 18:21:59 by jlange            #+#    #+#             */
/*   Updated: 2016/11/09 15:44:47 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_push_back(t_list **list, void *content, size_t content_size)
{
	t_list	*tmp;
	t_list	*new;

	tmp = *list;
	new = ft_create_elem(content, content_size);
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		tmp = new;
}
