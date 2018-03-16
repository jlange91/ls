/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 18:05:01 by jlange            #+#    #+#             */
/*   Updated: 2017/02/21 20:24:48 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_strncat_ls(char **s1, const char *s2, int nb)
{
	int i;

	i = 0;
	while (**s1)
		(*s1)++;
	if (**s1 == '\0')
	{
		while (s2[i] && nb > 0)
		{
			**s1 = s2[i];
			i++;
			(*s1)++;
			nb--;
		}
	}
	**s1 = '\0';
}

void	ft_strnncat_ls(char **s1, const char *s2, int nb1, int nb2)
{
	int i;

	i = 0;
	while (**s1)
		(*s1)++;
	if (**s1 == '\0')
	{
		while (s2[i] && nb1 > 0)
		{
			i++;
			nb1--;
		}
		while (s2[i] && nb2 > 0)
		{
			**s1 = s2[i];
			i++;
			(*s1)++;
			nb2--;
		}
	}
	**s1 = '\0';
}

void	ft_add_name(char **s1, const char *s2, t_file *file, int flags)
{
	int i;

	i = 0;
	if ((flags & 0b00000100000))
		ft_colors_l(file, s1);
	while (**s1)
		(*s1)++;
	if (**s1 == '\0')
	{
		while (s2[i])
		{
			**s1 = s2[i];
			i++;
			(*s1)++;
		}
	}
	**s1 = '\0';
	if ((flags & 0b00000100000))
		ft_strcat_ls(s1, RESET);
}

void	free_ls(t_file *root)
{
	if (root->right)
		free_ls(root->right);
	free(root->d_name);
	free(root->path);
	if (root->left)
		free_ls(root->left);
}
