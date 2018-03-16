/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_one_l.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 13:53:40 by jlange            #+#    #+#             */
/*   Updated: 2017/02/22 11:42:19 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static inline int	ft_init_file(t_file *file, char *name, t_len *len, int tmp)
{
	if (lstat(name, &(file->stat)) < 0)
		return (-1);
	file->d_name = ft_strdup(name);
	file->path = ft_strdup(name);
	file->major = major(file->stat.st_rdev);
	file->minor = minor(file->stat.st_rdev);
	file->uid = getpwuid(file->stat.st_uid);
	file->grp = getgrgid(file->stat.st_gid);
	tmp = ft_intlen(file->stat.st_nlink);
	len->lnk = (len->lnk < tmp) ? tmp : len->lnk;
	tmp = ft_strlen(file->uid->pw_name);
	len->uid = (len->uid < tmp) ? tmp : len->uid;
	tmp = ft_strlen(file->grp->gr_name);
	len->grp = (len->grp < tmp) ? tmp : len->grp;
	tmp = ft_intlen(file->stat.st_size);
	len->size = (len->size < tmp) ? tmp : len->size;
	if ((NORME ^ S_IFBLK) == 0 || (NORME ^ S_IFCHR) == 0)
	{
		tmp = ft_intlen(file->major);
		len->major = (len->major < tmp) ? tmp : len->major;
		tmp = ft_intlen(file->minor);
		len->minor = (len->minor < tmp) ? tmp : len->minor;
	}
	len->total += file->stat.st_blocks;
	return (0);
}

static inline void	ft_init(t_display_l *display)
{
	display->j = 0;
	display->k = 0;
	display->len.lnk = 0;
	display->len.uid = 0;
	display->len.grp = 0;
	display->len.size = 0;
	display->len.major = 0;
	display->len.minor = 0;
	display->len.total = 0;
}

static inline void	ft_tmp(t_display_l *display, char *av, t_file *file)
{
	if (errno == 20)
	{
		file[display->j].left = NULL;
		file[display->j].right = NULL;
		ft_init_file(&file[display->j], av, &display->len, 0);
		display->j++;
		display->k++;
	}
	else if (errno == 2)
	{
		if (ft_init_file(&file[display->j], av, &display->len, 0) < 0)
		{
			ft_error(av);
			write(1, "\n", 1);
		}
		display->j++;
		display->k++;
	}
}

static inline void	ft_tmp2(t_display_l *display, char *av, t_file *file)
{
	ft_init_file(&file[display->j], av, &display->len, 0);
	if (((file[display->j].stat.st_mode & 0xF000) ^ S_IFLNK) == 0)
	{
		file[display->j].left = NULL;
		file[display->j].right = NULL;
		display->j++;
		display->k++;
	}
	else
	{
		free(file[display->j].d_name);
		free(file[display->j].path);
	}
	closedir(display->dir);
}

int					display_one_file_l(char **av, int ac, int flags, int i)
{
	t_file			file[ac];
	t_display_l		display;

	ft_init(&display);
	while (av[i])
	{
		if ((display.dir = opendir(av[i])) == NULL)
			ft_tmp(&display, av[i], file);
		else
			ft_tmp2(&display, av[i], file);
		i++;
	}
	file[display.j].d_name = NULL;
	if (file[0].d_name != NULL)
	{
		ft_display_l(file, display.len, flags);
		free_tab(file);
	}
	if (display.j > 0 && display.j != i)
		write(1, "\n", 1);
	return (display.k - i);
}
