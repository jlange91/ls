/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 13:43:54 by jlange            #+#    #+#             */
/*   Updated: 2017/02/12 17:29:12 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_fill_arg(char **av, struct stat *stat, int nb)
{
	int i;

	i = 0;
	while (i < nb)
	{
		lstat(av[i], &stat[i]);
		i++;
	}
}

static void		ft_swap_arg(char **av, struct stat *stat)
{
	char			*tmp;
	struct stat		stattmp;
	int				i;

	i = 0;
	tmp = av[i];
	av[i] = av[i + 1];
	av[i + 1] = tmp;
	stattmp = stat[i];
	stat[i] = stat[i + 1];
	stat[i + 1] = stattmp;
}

void			ft_tri_arg_time(char **av, int flags, int nb)
{
	int				i;
	int				val;
	struct stat		stat[nb];

	ft_fill_arg(av, stat, nb);
	i = -1;
	if (!av[i + 1])
		return ;
	while (av[++i + 1])
	{
		val = stat[i + 1].st_mtime - stat[i].st_mtime;
		if (val == 0)
			val = ft_strcmp(av[i], av[i + 1]);
		if (!(flags & 0b00010) && val > 0)
		{
			ft_swap_arg(&av[i], &stat[i]);
			i = -1;
		}
		else if ((flags & 0b00010) && val < 0)
		{
			ft_swap_arg(&av[i], &stat[i]);
			i = -1;
		}
	}
}

void			ft_tri_arg(char **av, int flags)
{
	int		i;
	int		val;
	char	*tmp;

	i = -1;
	if (!av[i + 1])
		return ;
	while (av[++i + 1])
	{
		val = ft_strcmp(av[i], av[i + 1]);
		if (!(flags & 0b00010) && val > 0)
		{
			tmp = av[i];
			av[i] = av[i + 1];
			av[i + 1] = tmp;
			i = -1;
		}
		else if ((flags & 0b00010) && val < 0)
		{
			tmp = av[i];
			av[i] = av[i + 1];
			av[i + 1] = tmp;
			i = -1;
		}
	}
}
