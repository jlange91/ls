/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:26:04 by jlange            #+#    #+#             */
/*   Updated: 2017/02/22 17:50:00 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static inline int	ft_init_file(t_file *file, char *name, t_nm *nm)
{
	int				tmp;
	struct winsize	w;

	file->d_name = ft_strdup(file->dirent->d_name);
	file->path = ft_add_prefix(name, file->d_name);
	tmp = lstat(file->path, &(file->stat));
	if (tmp == -1)
	{
		write(1, "ft_ls: ", 7);
		write(1, file->d_name, ft_strlen(file->d_name));
		write(1, ": ", 2);
		ft_putstr(strerror(errno));
		write(1, "\n", 1);
		free(file->d_name);
		free(file->path);
		return (-1);
	}
	ioctl(0, TIOCGWINSZ, &w);
	nm->col = w.ws_col;
	nm->row = w.ws_row;
	tmp = ft_strlen(file->d_name);
	nm->max = (nm->max < tmp) ? tmp : nm->max;
	nm->nb_nm += 1;
	return (0);
}

static inline void	ft_tmp(t_file *file, int flags, char *name, t_nm nm)
{
	int i;

	i = 0;
	file->left = NULL;
	file->right = NULL;
	while (file[++i].dirent != NULL)
		init_fill_three(&file[i], &file[0], flags);
	if ((flags & 0b00010))
	{
		print_reverse_three(&file[0], flags, &nm);
		if (flags & 0b01000)
			ft_reverse_recursive(file, flags, name);
		free_ls(&file[0]);
		return ;
	}
	print_three(&file[0], flags, &nm);
	if (flags & 0b01000)
		ft_recursive(file, flags, name);
	free_ls(&file[0]);
}

void				fill_info_file(char *name, int nb_file, int flags)
{
	DIR		*dir;
	t_file	file[nb_file + 1];
	t_nm	nm;
	int		i;

	i = 0;
	nm.max = 0;
	nm.nb_nm = 0;
	nm.index = 0;
	if ((dir = opendir(name)) == NULL)
		return ;
	while ((file[i].dirent = readdir(dir)))
		if (ft_check_file(file[i].dirent->d_name, flags) == 1)
			if (ft_init_file(&file[i], name, &nm) == 0)
				i++;
	closedir(dir);
	if (i > 0)
		ft_tmp(file, flags, name, nm);
}

void				init_struct_file(char *name, int flags)
{
	int nb_file;

	nb_file = count_folder(name, flags);
	if ((flags & 0b10000))
		fill_info_file_l(name, nb_file, flags);
	else
		fill_info_file(name, nb_file, flags);
}
