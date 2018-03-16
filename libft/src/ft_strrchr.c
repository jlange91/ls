/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 18:33:13 by jlange            #+#    #+#             */
/*   Updated: 2016/02/07 18:33:14 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s) - 1;
	if (!c)
		return ((char *)s + i + 1);
	while (s[i] != 0 && s[i] != c)
		i--;
	if (s[i] == c)
		return ((char *)s + i);
	else
		return (0);
}
