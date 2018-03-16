/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 18:32:52 by jlange            #+#    #+#             */
/*   Updated: 2016/02/07 18:32:55 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (ft_strlen(s2) == 0)
		return (char *)(s1);
	while (s1[i])
	{
		j = i;
		k = 0;
		while (s2[k] == s1[j] && j < n)
		{
			j++;
			k++;
			if (s2[k] == '\0')
				return (char *)(s1 + i);
		}
		i++;
	}
	return (NULL);
}
