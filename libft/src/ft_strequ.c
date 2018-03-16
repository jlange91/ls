/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 18:28:20 by jlange            #+#    #+#             */
/*   Updated: 2016/02/07 18:28:22 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if (ft_strlen(s1) == ft_strlen(s2))
	{
		while (s1[i] == s2[i] && s1[i])
			i++;
		if (s1[i] == '\0')
			return (1);
		else
			return (0);
	}
	return (0);
}
