/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 18:19:54 by jlange            #+#    #+#             */
/*   Updated: 2016/02/07 18:19:56 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;
	unsigned char	*tmp2;
	unsigned char	uc;

	i = 0;
	tmp = (unsigned char *)dst;
	tmp2 = (unsigned char *)src;
	uc = (unsigned char)c;
	while (i < n)
	{
		tmp[i] = tmp2[i];
		if (tmp2[i] == uc)
			return (tmp + i + 1);
		i++;
	}
	return (NULL);
}
