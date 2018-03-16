/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_l.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 18:58:04 by jlange            #+#    #+#             */
/*   Updated: 2017/02/22 17:52:27 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static inline void	ft_tmp(t_file *file, int *tmp, t_len *len)
{
	file->major = major(file->stat.st_rdev);
	file->minor = minor(file->stat.st_rdev);
	file->uid = getpwuid(file->stat.st_uid);
	file->grp = getgrgid(file->stat.st_gid);
	*tmp = ft_intlen(file->stat.st_nlink);
	len->lnk = (len->lnk < *tmp) ? *tmp : len->lnk;
	*tmp = (file->uid) ? ft_strlen(file->uid->pw_name) : 3;
	len->uid = (len->uid < *tmp) ? *tmp : len->uid;
	*tmp = ft_strlen(file->grp->gr_name);
	len->grp = (len->grp < *tmp) ? *tmp : len->grp;
	*tmp = ft_intlen(file->stat.st_size);
	len->size = (len->size < *tmp) ? *tmp : len->size;
}

static inline int	ft_init_file(t_file *file, char *name, t_len *len, int tmp)
{
	file->d_name = ft_strdup(file->dirent->d_name);
	file->path = ft_add_prefix(name, file->d_name);
	tmp = lstat(file->path, &(file->stat));
	if (tmp == -1)
	{
		write(1, "ft_ls: ", 7);
		write(1, file->d_name, ft_strlen(file->d_name));
		write(1, ": ", 2);
		ft_putstr(strerror(errno));
		write(1, "\n", 1);
		free(file->d_name);
		free(file->path);
		return (-1);
	}
	ft_tmp(file, &tmp, len);
	if (((file->stat.st_mode & 0xF000) ^ S_IFBLK) == 0 ||
		((file->stat.st_mode & 0xF000) ^ S_IFCHR) == 0)
	{
		tmp = ft_intlen(file->major);
		len->major = (len->major < tmp) ? tmp : len->major;
		tmp = ft_intlen(file->minor);
		len->minor = (len->minor < tmp) ? tmp : len->minor;
	}
	len->total += file->stat.st_blocks;
	return (0);
}

void				ft_init(t_len *len)
{
	len->lnk = 0;
	len->uid = 0;
	len->grp = 0;
	len->size = 0;
	len->major = 0;
	len->minor = 0;
	len->total = 0;
}

void				ft_main_l(t_file *file, t_len len, int flags, char *name)
{
	int i;

	i = 0;
	file->left = NULL;
	file->right = NULL;
	while (file[++i].dirent != NULL)
		init_fill_three(&file[i], file, flags);
	if ((flags & 0b00010))
	{
		write(1, "total ", 6);
		ft_putnbr(len.total);
		write(1, "\n", 1);
		print_reverse_three_l(file, flags, len);
		if (flags & 0b01000)
			ft_reverse_recursive(file, flags, name);
		free_ls(file);
		return ;
	}
	write(1, "total ", 6);
	ft_putnbr(len.total);
	write(1, "\n", 1);
	print_three_l(file, flags, len);
	if (flags & 0b01000)
		ft_recursive(file, flags, name);
	free_ls(file);
}

void				fill_info_file_l(char *name, int nb_file, int flags)
{
	DIR				*dir;
	t_file			file[nb_file + 1];
	t_len			len;
	int				i;
	struct stat		stat;

	i = 0;
	ft_init(&len);
	lstat(name, &stat);
	if (((stat.st_mode & 0xF000) ^ S_IFLNK) == 0)
		return ;
	if ((dir = opendir(name)) == NULL)
		return ;
	while ((file[i].dirent = readdir(dir)))
		if (ft_check_file(file[i].dirent->d_name, flags) == 1)
			if (ft_init_file(&file[i], name, &len, 0) == 0)
				i++;
	closedir(dir);
	if (i > 0)
		ft_main_l(file, len, flags, name);
}
