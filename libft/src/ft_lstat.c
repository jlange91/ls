/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 18:17:00 by jlange            #+#    #+#             */
/*   Updated: 2016/02/07 18:17:01 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstat(t_list **list, unsigned int n)
{
	t_list			*buf;
	unsigned int	i;

	i = 0;
	buf = *list;
	if (!list)
		return (NULL);
	while (i < n)
		buf = buf->next;
	return (buf);
}
