/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_maj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 19:15:46 by jlange            #+#    #+#             */
/*   Updated: 2016/12/04 20:34:54 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_intlenbase(intmax_t nb, int base)
{
	int len;

	len = 1;
	while ((nb = nb / base))
		len++;
	return (len);
}

char			*ft_itoa_base_maj(intmax_t n, int base)
{
	int			len;
	char		*str;
	int			c;

	len = ft_intlenbase(n, base) + 1;
	if (!(str = (char *)malloc(sizeof(char) * (len))))
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		c = n % base;
		str[len] = (c < 10) ? c + '0' : (c - 10) + 'A';
		n = n / base;
	}
	return (str);
}
