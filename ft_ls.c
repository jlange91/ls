/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:26:04 by jlange            #+#    #+#             */
/*   Updated: 2017/01/11 20:53:00 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		init_flags(char **av, int *flags)
{
	int j;
	int i;
	int error;

	j = 0;
	while (av[++j] && av[j][0] == '-')
	{
		if (av[j][0] == '-' && av[j][1] == '-')
			return (0);
		i = 0;
		while (av[j][++i])
		{
			error = 0;
			(av[j][i] == 'l') ? (*flags |= 0b10000) : (error += 1);
			(av[j][i] == 'R') ? (*flags |= 0b01000) : (error += 1);
			(av[j][i] == 'a') ? (*flags |= 0b00100) : (error += 1);
			(av[j][i] == 'r') ? (*flags |= 0b00010) : (error += 1);
			(av[j][i] == 't') ? (*flags |= 0b00001) : (error += 1);
			*flags &= (av[j][i] == '1') ? 0b01111 : 0b11111;
			error -= (av[j][i] == '1') ? 1 : 0;
			if (error == 5)
				return (av[j][i]);
		}
	}
	return (0);
}

int main(int ac, char **av)
{
	int flags;
	t_ls ls;
	int ret;

	flags = 0;
	if (av[1])
	{
		if ((ret = init_flags(av, &flags)) != 0)
		{
			ft_printf("ntm charactere de merde : %c", ret);
			return (0);
		}
		ft_printf("%b", flags);
		if ((flags & 0b01000) != 0)
		{

		}
	}
}
