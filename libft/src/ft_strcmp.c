/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 18:27:16 by jlange            #+#    #+#             */
/*   Updated: 2016/11/03 22:02:33 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, const char *s2)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	while (*tmp1 == *tmp2)
		if (!(*tmp1++ + *tmp2++))
			return (0);
	return (*tmp1 - *tmp2);
}
