/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:26:04 by jlange            #+#    #+#             */
/*   Updated: 2017/01/20 20:17:50 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*void	ft_test9(t_file *root)
{
	while (1)
	{
		printf("%s\n", root->dirent->d_name);
		char c;
		read(1, &c, 1);
		if (c == 'l')
		{
			if (root->left)
				ft_test9(root->left);
		}
		else if (c == 'r')
		{
			if (root->right)
				ft_test9(root->right);
		}
		else if (c == 'b')
			return ;
	}
}*/

int		fill_info_file(char *name, int nb_file, int flags)
{
	DIR		*dir;
	t_file	file[nb_file + 1];
	int i;

	i = 0;
	if ((dir = opendir(name)) == NULL)
		return (-1);
	while ((file[i].dirent = readdir(dir)))
	{
		if (file[i].dirent->d_name[0] != '.' || (flags & 0b00100))
		{
			file[i].d_name = ft_strdup(file[i].dirent->d_name);
			file[i].path = ft_add_prefix(name, file[i].d_name);
			lstat(file[i].path, &(file[i].stat));
			if ((flags & 0b10000))
			{
				file[i].uid = getpwuid(file[i].stat.st_uid);
				file[i].grp = getgrgid(file[i].stat.st_gid);
			}
			i++;
		}
	}
	closedir(dir);
	if (i > 0)
	{
		i = 1;
		file->left = NULL;
		file->right = NULL;
		while (file[i].dirent != NULL)
		{
			if ((flags & 0b00001))
				fill_three_time(&file[i], &file[0]);
			else
				fill_three(&file[i], &file[0]);
			i++;
		}
		if ((flags & 0b00010))
		{
			ft_print_reverse_three(&file[0], flags);
			if (flags & 0b01000)
				ft_reverse_recursive(file, flags, name);
			return (0);
		}
		ft_print_three(&file[0], flags);
		if (flags & 0b01000)
			ft_recursive(file, flags, name);
	}
	return (0);
}

int		init_struct_file(char *name, int flags)
{
	int nb_file;

	nb_file = count_folder(name, flags);
	fill_info_file(name, nb_file, flags);
	return (1);
}

int		ft_ls(int flags, char **av)
{
	int i;
	int test;

	i = 1;
	test = 1;
	while (av[i] && test == 1)
	{
		if (av[i][0] == '-' && av[i][1] != '\0')
		{
			if (av[i][1] == '-')
			{
				i++;
				break ;
			}
			i++;
		}
		else
			test = 0;
	}
	if (!av[i])
		init_struct_file(".", flags);
	while (av[i])
	{
		init_struct_file(av[i], flags);
		i++;
	}
	return (0);
}

int main(int ac, char **av)
{
	int flags;
	int ret;

	ac = (int)ac;
	flags = 0;
	if ((ret = init_flags(av, &flags)) != 0)
	{
		write(1, "ls: illegal option -- ", 22);
		write(1, &ret, 1);
		write(1, "\n", 1);
		return (0);
	}
	ft_ls(flags, av);
}
