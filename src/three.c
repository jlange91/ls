/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:54:47 by jlange            #+#    #+#             */
/*   Updated: 2017/01/19 19:30:21 by jlange           ###   ########.fr       */
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
	acl_t acl;

	if (root->left)
		ft_print_three(root->left, flags);
	if ((flags & 0b10000))
	{
		print_rights(root->stat);
		if (listxattr(root->path, NULL, 0, XATTR_NOFOLLOW) > 0)
		{
			write(1, "@  ", 3);
		}
		else if ((acl = acl_get_file(root->path, ACL_TYPE_EXTENDED)))
		{
			write(1, "+  ", 3);
			acl_free((void*)acl);
		}
		else
			write(1, "  ", 2);
	}
	ft_putendl(root->d_name);
	if (root->right)
		ft_print_three(root->right, flags);
}

void	ft_print_reverse_three(t_file *root, int flags)
{
	acl_t acl;

	if (root->right)
		ft_print_reverse_three(root->right, flags);
	if ((flags & 0b10000))
	{
		print_rights(root->stat);
		if (listxattr(root->path, NULL, 0, XATTR_NOFOLLOW) > 0)
		{
			write(1, "@  ", 3);
		}
		else if ((acl = acl_get_file(root->path, ACL_TYPE_EXTENDED)))
		{
			write(1, "+  ", 3);
			acl_free((void*)acl);
		}
		else
			write(1, "  ", 2);
	}
	ft_putendl(root->d_name);
	if (root->left)
		ft_print_reverse_three(root->left, flags);
}
