/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 16:45:23 by jlange            #+#    #+#             */
/*   Updated: 2017/02/21 15:58:31 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_start_ls(char *name, int flags, int *test, int nb)
{
	int nb_file;

	nb_file = count_folder(name, flags);
	if (nb_file == -1)
		return ;
	if (*test < 0 || nb > 1)
	{
		ft_putstr(name);
		write(1, ":\n", 2);
	}
	if ((flags & 0b10000))
		fill_info_file_l(name, nb_file, flags);
	else
		fill_info_file(name, nb_file, flags);
	if (*test < -1)
	{
		write(1, "\n", 1);
	}
	(*test)++;
}

static void		ft_ls(int flags, char **av, int ac, int ret)
{
	int i;
	int test;

	i = 0;
	if (!av[i])
	{
		init_struct_file(".", flags);
		return ;
	}
	test = ((flags & 0b10000)) ? display_one_file_l(av, ac, flags, 0) :
		display_one_file(av, ac, flags, 0);
	test = (test == -1) ? 0 : test;
	while (av[i])
	{
		ft_start_ls(av[i], flags, &test, ac - ret);
		i++;
	}
}

static void		print_usage(int ret)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	write(2, &ret, 1);
	ft_putstr_fd("\nusage: ft_ls [-AFGRaglort1] [file ...]\n", 2);
}

static int		init_index_av(char **av)
{
	int test;
	int ret;

	test = 1;
	ret = 1;
	while (av[ret] && test == 1)
	{
		if (av[ret][0] == '-' && av[ret][1] != '\0')
		{
			if (av[ret][1] == '-')
			{
				ret++;
				break ;
			}
			ret++;
		}
		else
			test = 0;
	}
	return (ret);
}

int				main(int ac, char **av)
{
	int flags;
	int ret;
	int test;

	flags = 0;
	test = 1;
	if ((ret = init_flags(av, &flags)) != 0)
	{
		print_usage(ret);
		return (1);
	}
	ret = init_index_av(av);
	if ((flags & 0b00001))
		ft_tri_arg_time(&av[ret], flags, ac - ret);
	else
		ft_tri_arg(&av[ret], flags);
	ft_ls(flags, &av[ret], ac, ret);
}
