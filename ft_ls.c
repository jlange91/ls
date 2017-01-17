/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:26:04 by jlange            #+#    #+#             */
/*   Updated: 2017/01/17 21:00:53 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_test2(t_file *root)
{
	while (1)
	{
		printf("%s\n", root->dirent->d_name);
		char c;
		read(1, &c, 1);
		if (c == 'l')
		{
			if (root->left)
				ft_test2(root->left);
		}
		else if (c == 'r')
		{
			if (root->right)
				ft_test2(root->right);
		}
		else if (c == 'b')
			return ;
	}
}

void	print(t_file *file)
{
	int i;

	i = 0;
	while (file[i].dirent != NULL)
	{
		printf("%s\n", file[i].d_name);
		i++;
	}
}

char	*ft_add_prefix(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		j;
	if (!s1 || !s2)
		return (NULL);
	ret = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	i = -1;
	j = -1;
	if (ret == NULL)
		return (NULL);
	while (s1[++i])
	{
		ret[i] = s1[i];
	}
	ret[i] = '/';
	++i;
	while (s2[++j])
	{
		ret[i] = s2[j];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

void	ft_recursive(char *name, int flags)
{
	DIR *dir;
	struct dirent *dirent;
	struct stat stat;
	char *tmp;

	if ((dir = opendir(name)) == NULL)
		return ;
	while ((dirent = readdir(dir)))
	{
		tmp = ft_add_prefix(name, dirent->d_name);
		lstat(tmp, &stat);
		if (dirent->d_name[0] != '.' && (stat.st_mode & S_IFDIR) != 0)
		{
			write(1, tmp, ft_strlen(tmp));
			ft_putendl(":");
			init_struct_file(tmp, flags);
		}
	}
	closedir(dir);
}

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
		file[i].d_name = ft_strdup(file[i].dirent->d_name);
		lstat(file[i].dirent->d_name, &(file[i].stat));
		if ((flags & 0b10000))
		{
			file[i].uid = getpwuid(file[i].stat.st_uid);
			file[i].grp = getgrgid(file[i].stat.st_gid);
		}
	//	printf("%s\n", file[i].dirent->d_name);
		i++;
	}
	i = 1;
	file->left = NULL;
	file->right = NULL;
	while (file[i].dirent != NULL)
	{
		fill_three(&file[i], &file[0]);
		i++;
	}
//	ft_test2(&file[0]);
	ft_print_three(&file[0]);
	closedir(dir);
	ft_recursive(name, flags);
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
		if (av[i][0] == '-')
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

	flags = 0;
	if (av[1])
	{
		if ((ret = init_flags(av, &flags)) != 0)
		{
			ft_printf("ntm charactere de merde : %c\n", ret);
			return (0);
		}
		ft_printf("%b\n", flags);
		if ((flags & 0b01000) != 0)
		{
			ft_ls(flags, av);
		}
	}
}
