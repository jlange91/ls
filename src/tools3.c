/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:12:52 by jlange            #+#    #+#             */
/*   Updated: 2017/02/21 18:26:57 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_acl(t_file *root, char **buf, t_len *len_arg)
{
	acl_t acl;

	if (listxattr(root->path, NULL, 0, XATTR_NOFOLLOW) > 0)
	{
		ft_charcat(buf, '@');
		len_arg->lnk++;
	}
	else if ((acl = acl_get_file(root->path, ACL_TYPE_EXTENDED)))
	{
		ft_charcat(buf, '+');
		acl_free((void*)acl);
		len_arg->lnk++;
	}
}

void	ft_itoa_ls(uintmax_t n, char *buf)
{
	int len;

	len = ft_intlen(n) + 2;
	buf[--len] = '\0';
	while (len-- != 1)
	{
		buf[len] = n % 10 + '0';
		n = n / 10;
	}
	buf[0] = ' ';
}

void	ft_nb_lnk(t_file *root, char *buf, t_len *len_arg, t_len len)
{
	len_arg->lnk += ft_intlen(root->stat.st_nlink);
	add_padding(&buf, len.lnk - len_arg->lnk + 1);
	ft_itoa_ls(root->stat.st_nlink, buf);
}

void	ft_print_lnk(t_file *root, char **buf)
{
	char	tmp[LNK_BUFF_SIZE];
	int		len;

	if ((len = readlink(root->path, tmp, 9999999)) != -1)
	{
		tmp[len] = '\0';
		ft_strcat_ls(buf, " -> ");
		ft_strcat_ls(buf, tmp);
	}
	else
		return ;
}

int		ft_strlen2(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
