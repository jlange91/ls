/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:43:28 by jlange            #+#    #+#             */
/*   Updated: 2017/02/22 11:28:54 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static inline int	ft_init_file(t_file *file, char *name, t_nm *nm)
{
	int				tmp;
	struct winsize	w;

	if (lstat(name, &(file->stat)) < 0)
		return (-1);
	file->left = NULL;
	file->right = NULL;
	file->d_name = ft_strdup(name);
	file->path = ft_strdup(name);
	ioctl(0, TIOCGWINSZ, &w);
	nm->col = w.ws_col;
	nm->row = w.ws_row;
	tmp = ft_strlen(file->d_name);
	nm->max = (nm->max < tmp) ? tmp : nm->max;
	nm->nb_nm += 1;
	return (0);
}

static void			ft_display(t_file *file, int flags, t_nm *nm)
{
	int i;

	i = 0;
	while (file[i].d_name != NULL)
	{
		ft_print_name(&file[i], flags, nm);
		i++;
	}
}

static inline void	ft_init(t_display *display)
{
	display->j = 0;
	display->k = 0;
	display->nm.max = 0;
	display->nm.nb_nm = 0;
	display->nm.index = 0;
}

static inline void	ft_tmp(t_display *display, t_file *file, DIR *dir,
		char *av)
{
	if ((dir = opendir(av)) == NULL)
	{
		if (errno == 20)
		{
			ft_init_file(&file[display->j], av, &display->nm);
			display->j++;
			display->k++;
		}
		else if (errno == 2)
		{
			if (ft_init_file(&file[display->j], av, &display->nm) == 0)
				display->j++;
			else
			{
				ft_error(av);
				write(1, "\n", 1);
			}
			display->k++;
		}
	}
	else
		closedir(dir);
}

int					display_one_file(char **av, int ac, int flags, int i)
{
	t_file		file[ac];
	DIR			*dir;
	t_display	display;

	ft_init(&display);
	dir = NULL;
	while (av[i])
	{
		ft_tmp(&display, file, dir, av[i]);
		i++;
	}
	file[display.j].d_name = NULL;
	if (file[0].d_name != NULL)
	{
		ft_display(file, flags, &display.nm);
		free_tab(file);
	}
	if (display.j > 0 && display.j != i)
		write(1, "\n", 1);
	return (display.k - i);
}
