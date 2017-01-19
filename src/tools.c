/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:26:04 by jlange            #+#    #+#             */
/*   Updated: 2017/01/18 18:55:27 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_add_prefix(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		j;
	if (!s1 || !s2)
		return (NULL);
	ret = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	i = -1;
	j = -1;
	if (ret == NULL)
		return (NULL);
	while (s1[++i])
		ret[i] = s1[i];
	if (s1[0] != '/' || s1[1] != '\0')
	{
		ret[i] = '/';
		++i;
	}
	while (s2[++j])
	{
		ret[i] = s2[j];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
