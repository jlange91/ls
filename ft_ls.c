/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:26:04 by jlange            #+#    #+#             */
/*   Updated: 2017/01/18 18:55:27 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_test9(t_file *root)
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
		ret[i] = s1[i];
	if (s1[0] != '/' || s1[1] != '\0')
	{
		ret[i] = '/';
		++i;
	}
	while (s2[++j])
	{
		ret[i] = s2[j];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

void	ft_recursive(t_file *root, int flags, char *name)
{
	char *tmp;

	if (root->left)
		ft_recursive(root->left, flags, name);
	if (root->d_name[0] != '.' && ((root->stat.st_mode & 0xF000) ^ S_IFDIR) == 0)
	{
		tmp = ft_add_prefix(name, root->d_name);
		write(1, "\n", 1);
		write(1, tmp, ft_strlen(tmp));
		ft_putendl(":");
		init_struct_file(tmp, flags);
	}
	if (root->right)
		ft_recursive(root->right, flags, name);
}

void	ft_reverse_recursive(t_file *root, int flags, char *name)
{
	char *tmp;

	if (root->right)
		ft_reverse_recursive(root->right, flags, name);
	if (root->d_name[0] != '.' && ((root->stat.st_mode & 0xF000) ^ S_IFDIR) == 0)
	{
		tmp = ft_add_prefix(name, root->d_name);
		write(1, "\n", 1);
		write(1, tmp, ft_strlen(tmp));
		ft_putendl(":");
		init_struct_file(tmp, flags);
	}
	if (root->left)
		ft_reverse_recursive(root->left, flags, name);
}

int		fill_info_file(char *name, int nb_file, int flags)
{
	DIR		*dir;
	t_file	file[nb_file + 1];
	int i;
	char *tmp;

	i = 0;
	if ((dir = opendir(name)) == NULL)
		return (-1);
	while ((file[i].dirent = readdir(dir)))
	{
		file[i].d_name = ft_strdup(file[i].dirent->d_name);
		tmp = ft_add_prefix(name, file[i].d_name);
		lstat(tmp, &(file[i].stat));
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
	closedir(dir);
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

	flags = 0;
	if ((ret = init_flags(av, &flags)) != 0)
	{
		ft_printf("ntm charactere de merde : %c\n", ret);
		return (0);
	}
	ft_ls(flags, av);
}
