/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 18:16:30 by jlange            #+#    #+#             */
/*   Updated: 2016/12/06 17:07:04 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(intmax_t n)
{
	int			len;
	char		*str;
	int			neg;

	if (n == -9223372036854775807 - 1)
		return (ft_strdup("-9223372036854775808"));
	len = ft_intlen(n) + 1;
	neg = (n < 0) ? 1 : 0;
	len += (n < 0) ? 1 : 0;
	n = (n < 0) ? n * -1 : n;
	if (!(str = (char *)malloc(sizeof(char) * (len))))
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
