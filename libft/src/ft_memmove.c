/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 18:21:16 by jlange            #+#    #+#             */
/*   Updated: 2016/02/07 18:21:17 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*tmp_dst;
	const char		*tmp2_src;

	tmp_dst = dst;
	tmp2_src = src;
	if (len <= 0)
		return (dst);
	if (tmp_dst < tmp2_src)
		while (len-- > 0)
			*tmp_dst++ = *tmp2_src++;
	else
	{
		tmp_dst += len;
		tmp2_src += len;
		while (len-- > 0)
			*--tmp_dst = *--tmp2_src;
	}
	return (dst);
}
