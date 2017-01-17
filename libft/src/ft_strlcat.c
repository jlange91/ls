/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 18:30:09 by jlange            #+#    #+#             */
/*   Updated: 2016/02/07 18:30:11 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		j;
	int		a;
	size_t	i;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
	{
		if (i == size)
			return (size + ft_strlen(src));
		i++;
	}
	a = i;
	while (src[j] != '\0' && i < (size - 1))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	j = 0;
	while (src[j] != '\0')
		j++;
	dst[i] = '\0';
	return (a + j);
}
