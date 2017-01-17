/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 18:29:53 by jlange            #+#    #+#             */
/*   Updated: 2016/11/03 18:01:21 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	i = -1;
	j = -1;
	if (ptr == NULL)
		return (NULL);
	while (s1[++i])
	{
		ptr[i] = s1[i];
	}
	if (s1[i] == '\0')
	{
		while (s2[++j])
		{
			ptr[i] = s2[j];
			i++;
		}
	}
	ptr[i] = '\0';
	return (ptr);
}
