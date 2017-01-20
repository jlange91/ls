/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 17:23:51 by jlange            #+#    #+#             */
/*   Updated: 2017/01/20 21:28:24 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_acl(t_file *root, char *buf)
{
	acl_t acl;

	if (listxattr(root->path, NULL, 0, XATTR_NOFOLLOW) > 0)
		ft_charcat(&buf , '@');
	else if ((acl = acl_get_file(root->path, ACL_TYPE_EXTENDED)))
	{
		ft_charcat(&buf , '+');
		acl_free((void*)acl);
	}
}

void	ft_itoa_ls(uintmax_t n, char *buf)
{
	int			len;

	len = ft_intlen(n) + 2;
	buf[--len] = '\0';
	while (len-- != 1)
	{
		buf[len] = n % 10 + '0';
		n = n / 10;
	}
	buf[0] = ' ';
}

void	ft_nb_lnk(t_file *root, char *buf, t_len *len_arg)
{
	len_arg->lnk = ft_intlen(root->stat.st_nlink);
	ft_itoa_ls(root->stat.st_nlink, buf);
}

void	ft_tmp_for_buf(t_file *root, char *buf)
{
	t_len len_arg;

	print_rights(root->stat, &buf);
	ft_acl(root, buf);
	ft_nb_lnk(root, buf, &len_arg);
	ft_strcat_ls(&buf , "	");
	ft_add_name(&buf, root->d_name);
}

void	ft_print_lflag(t_file *root)
{
	char buf[2048];

	buf[0] = '\0';
	ft_tmp_for_buf(root, buf);
	write(1, buf, ft_strlen(buf));
}
