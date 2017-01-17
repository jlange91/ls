/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:26:04 by jlange            #+#    #+#             */
/*   Updated: 2017/01/15 23:13:31 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		myft_strlen(const char *s)
{
	unsigned	x;
	int			len;

	len = 0;
	while (1)
	{
		x = *(unsigned*)s;
		if ((x & 0xFF) == 0)
			return (len);
		if ((x & 0xFF00) == 0)
			return (len + 1);
		if ((x & 0xFF0000) == 0)
			return (len + 2);
		if ((x & 0xFF000000) == 0)
			return (len + 3);
		s += 4;
		len += 4;
	}
}

int		count_folder(char *name, int flags)
{
	struct dirent *dirent;
	DIR *dir;
	int len;

	len = 0;
	if ((dir = opendir(name)) == NULL)
	{
		perror("");
		return (-1);
	}
	while ((dirent = readdir(dir)))
		len++;
	closedir(dir);
	return (len);
}

int		mystrcmp(char *s1, const char *s2)
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

void	echanger(t_file *file, int a, int b)
{
	t_file tmp;

	tmp = file[a];
	file[a] = file[b];
	file[b] = tmp;
}

void	ft_test(t_file *file)
{
	int i;

	i = 0;
	while (file[i].dirent != NULL)
	{
		printf("%d   %s\n", i, file[i].dirent->d_name);
		i++;
	}
}

void	fill_three(t_file *new, t_file *root)
{
	int nb;

	new->left = NULL;
	new->right = NULL;
	while (1)
	{
		nb = mystrcmp(new->dirent->d_name, root->dirent->d_name);
		if (nb > 0)
		{
			if (root->right == NULL)
			{
				root->right = new;
				return ;
			}
			else
				root = root->right;
		}
		else
		{
			if (root->left == NULL)
			{
				root->left = new;
				return ;
			}
			else
				root = root->left;
		}
	}
}

void	ft_print_three(t_file *root)
{
	if (root->left)
		ft_print_three(root->left);
	printf("%s\n", root->dirent->d_name);
	if (root->right)
		ft_print_three(root->right);
}

void	ft_print_reverse_three(t_file *root)
{
	if (root->right)
		ft_print_reverse_three(root->right);
	printf("%s\n", root->dirent->d_name);
	if (root->left)
		ft_print_reverse_three(root->left);
}

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
		lstat(file[i].dirent->d_name, &(file[i].stat));
		if ((flags & 0b10000))
		{
			file[i].uid = getpwuid(file[i].stat.st_uid);
			file[i].grp = getgrgid(file[i].stat.st_gid);
		}
		if (i > 0)
			printf("%d   %s\n",i, file[i - 1].dirent->d_name);
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

	i = 1;
	while (av[i] && av[i][0] == '-')
		i++;
	while (av[i])
	{
		init_struct_file(av[i], flags);
		i++;
	}
	return (0);
}

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
