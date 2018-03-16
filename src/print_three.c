/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 17:35:19 by jlange            #+#    #+#             */
/*   Updated: 2017/02/17 16:14:55 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_three_l(t_file *root, int flags, t_len len)
{
	if (root->left)
		print_three_l(root->left, flags, len);
	ft_print_lflag(root, len, flags);
	if (root->right)
		print_three_l(root->right, flags, len);
}

void	print_reverse_three_l(t_file *root, int flags, t_len len)
{
	if (root->right)
		print_reverse_three_l(root->right, flags, len);
	ft_print_lflag(root, len, flags);
	if (root->left)
		print_reverse_three_l(root->left, flags, len);
}

void	print_three(t_file *root, int flags, t_nm *nm)
{
	if (root->left)
		print_three(root->left, flags, nm);
	ft_print_name(root, flags, nm);
	if (root->right)
		print_three(root->right, flags, nm);
}

void	print_reverse_three(t_file *root, int flags, t_nm *nm)
{
	if (root->right)
		print_reverse_three(root->right, flags, nm);
	ft_print_name(root, flags, nm);
	if (root->left)
		print_reverse_three(root->left, flags, nm);
}
