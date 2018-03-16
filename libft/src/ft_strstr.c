/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 18:33:36 by jlange            #+#    #+#             */
/*   Updated: 2016/02/07 18:33:38 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;
	int k;

	i = 0;
	if (ft_strlen(s2) == 0)
		return (char *)(s1);
	while (s1[i])
	{
		j = i;
		k = 0;
		while (s2[k] == s1[j])
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
