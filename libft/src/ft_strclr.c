/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 18:27:00 by jlange            #+#    #+#             */
/*   Updated: 2016/11/03 17:20:16 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strclr(char *s)
{
	int	i;

	i = 0;
	if (!(s))
		return ;
	while (s[i])
	{
		s[i] = '\0';
		i++;
	}
}
