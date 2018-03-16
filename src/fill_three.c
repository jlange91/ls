/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:54:47 by jlange            #+#    #+#             */
/*   Updated: 2017/02/12 18:03:56 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		fill_three(t_file *new, t_file *root, int nb)
{
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

static void		fill_three_time(t_file *new, t_file *root, long int nb)
{
	while (1)
	{
		nb = root->stat.st_mtime - new->stat.st_mtime;
		nb = (nb == 0) ? ft_strcmp(new->d_name, root->d_name) : nb;
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

void			init_fill_three(t_file *new, t_file *root, int flags)
{
	new->left = NULL;
	new->right = NULL;
	if ((flags & 0b00001))
		fill_three_time(new, root, 0);
	else
		fill_three(new, root, 0);
}
