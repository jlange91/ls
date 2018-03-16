/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 17:23:51 by jlange            #+#    #+#             */
/*   Updated: 2017/02/21 19:10:29 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static inline void		ft_init(t_print_l *struc, t_file *root, char *buf,
		t_len len)
{
	struc->buf = buf;
	struc->len = len;
	struc->tmp = buf;
	struc->timenow = time(0);
	struc->strtime = ctime(&root->stat.st_mtime);
	struc->len_arg.lnk = 0;
	root->uid = getpwuid(root->stat.st_uid);
	root->grp = getgrgid(root->stat.st_gid);
	struc->len_arg.uid = (root->uid) ? ft_strlen(root->uid->pw_name) : 3;
	struc->len_arg.grp = ft_strlen(root->grp->gr_name);
	struc->len_arg.size = ft_intlen(root->stat.st_size);
	struc->len_arg.major = ft_intlen(root->major);
	struc->len_arg.minor = ft_intlen(root->minor);
}

static inline void		ft_tmp_for_buf2(t_file *root, t_print_l struc)
{
	if (struc.tmp[0] != 'c' && struc.tmp[0] != 'b')
	{
		add_padding(&struc.buf, struc.len.size - struc.len_arg.size +
				struc.len.major + struc.len.minor +
				((struc.len.major > 0 || struc.len.minor > 0) ? 2 : 1));
		ft_itoa_ls(root->stat.st_size, struc.buf);
	}
	else
	{
		add_padding(&struc.buf, struc.len.major - struc.len_arg.major + 1);
		ft_itoa_ls(root->major, struc.buf);
		ft_charcat(&struc.buf, ',');
		add_padding(&struc.buf, struc.len.minor - struc.len_arg.minor);
		ft_itoa_ls(root->minor, struc.buf);
	}
	ft_charcat(&struc.buf, ' ');
	ft_strnncat_ls(&struc.buf, struc.strtime, 4, 7);
}

static inline void		ft_tmp_for_buf3(t_file *root, t_print_l struc,
		int flags)
{
	if ((struc.timenow - 15778800) > root->stat.st_mtime ||
			struc.timenow < root->stat.st_mtime)
	{
		if (struc.timenow < root->stat.st_mtime)
			ft_strcat_ls(&struc.buf, " 10000");
		else
		{
			ft_strcat_ls(&struc.buf, " ");
			ft_strnncat_ls(&struc.buf, struc.strtime, 20, 4);
		}
	}
	else
		ft_strnncat_ls(&struc.buf, struc.strtime, 11, 5);
	ft_strcat_ls(&struc.buf, " ");
	ft_add_name(&struc.buf, root->d_name, root, flags);
	if ((flags & 0b01000000))
		print_flag_f(root, &struc.buf);
	ft_print_lnk(root, &struc.buf);
	ft_charcat(&struc.buf, '\n');
}

static inline void		ft_tmp_for_buf(t_file *root, char *buf, t_len len,
		int flags)
{
	t_print_l struc;

	ft_init(&struc, root, buf, len);
	print_rights(root->stat, &buf);
	ft_acl(root, &struc.buf, &struc.len_arg);
	ft_nb_lnk(root, struc.buf, &struc.len_arg, struc.len);
	add_padding(&struc.buf, 1);
	if ((flags & 0b0010000000) == 0)
	{
		(root->uid) ? ft_strcat_ls(&struc.buf, root->uid->pw_name) :
		ft_strcat_ls(&struc.buf, "504");
		add_padding(&struc.buf, struc.len.uid - struc.len_arg.uid + 2);
	}
	if ((flags & 0b0100000000) == 0)
	{
		ft_strcat_ls(&struc.buf, root->grp->gr_name);
		add_padding(&struc.buf, struc.len.grp - struc.len_arg.grp);
	}
	ft_tmp_for_buf2(root, struc);
	ft_tmp_for_buf3(root, struc, flags);
}

void					ft_print_lflag(t_file *root, t_len len, int flags)
{
	char buf[L_BUFF_SIZE];

	buf[0] = '\0';
	ft_tmp_for_buf(root, buf, len, flags);
	write(1, buf, ft_strlen(buf));
}
