/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:26:04 by jlange            #+#    #+#             */
/*   Updated: 2017/01/18 18:55:27 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_test(char *d_name)
{
	if (d_name[0] == '.')
	{
		if (d_name[1] == '\0' || (d_name[1] == '.' && d_name[2] == '\0'))
			return (0);
		else
			return (1);
	}
	return (1);
}

void			ft_recursive(t_file *root, int flags, char *name)
{
	char *tmp;

	if (root->left)
		ft_recursive(root->left, flags, name);
	if (ft_test(root->d_name) &&
	((root->stat.st_mode & 0xF000) ^ S_IFDIR) == 0)
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

void			ft_reverse_recursive(t_file *root, int flags, char *name)
{
	char *tmp;

	if (root->right)
		ft_reverse_recursive(root->right, flags, name);
	if (ft_test(root->d_name) &&
	((root->stat.st_mode & 0xF000) ^ S_IFDIR) == 0)
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
