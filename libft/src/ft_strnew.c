/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 18:32:36 by jlange            #+#    #+#             */
/*   Updated: 2016/02/07 18:32:39 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * size + 1);
	if (ptr == NULL)
		return (NULL);
	else
	{
		ft_strclr(ptr);
		*ptr = '\0';
	}
	return (ptr);
}
