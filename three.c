/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:54:47 by jlange            #+#    #+#             */
/*   Updated: 2017/01/18 19:51:56 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	fill_three(t_file *new, t_file *root)
{
	int nb;

	new->left = NULL;
	new->right = NULL;
	while (1)
	{
		nb = ft_strcmp(new->d_name, root->d_name);
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

void	fill_three_time(t_file *new, t_file *root)
{
	int nb;

	new->left = NULL;
	new->right = NULL;
	while (1)
	{
		nb = ft_strcmp(new->d_name, root->d_name);
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

void	ft_print_three(t_file *root, int flags)
{
	if (root->left)
		ft_print_three(root->left, flags);
	if (root->d_name[0] != '.' || (flags & 0b00100))
	{
		if ((flags & 0b10000))
		{
			print_rights(root->stat);
			write(1, "  ", 2);
		}
		ft_putendl(root->d_name);
	}
	if (root->right)
		ft_print_three(root->right, flags);
}

void	ft_print_reverse_three(t_file *root, int flags)
{
	if (root->right)
		ft_print_reverse_three(root->right, flags);
	if (root->d_name[0] != '.' || (flags & 0b00100))
	{
		if ((flags & 0b10000))
		{
			print_rights(root->stat);
			write(1, "  ", 2);
		}
		ft_putendl(root->d_name);
	}
	if (root->left)
		ft_print_reverse_three(root->left, flags);
}
