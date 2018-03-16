/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 18:28:02 by jlange            #+#    #+#             */
/*   Updated: 2017/02/12 20:02:17 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_name(t_file *file, int flags)
{
	int mode;

	mode = file->stat.st_mode & 0xF000;
	if ((flags & 0b00100000))
		ft_colors(file);
	else
		ft_putstr(file->d_name);
	if ((flags & 0b01000000))
	{
		if ((mode ^ S_IFDIR) == 0)
			write(1, "/", 1);
		else if ((mode ^ S_IFLNK) == 0)
			write(1, "@", 1);
		else if ((mode ^ S_IFSOCK) == 0)
			write(1, "=", 1);
		else if ((mode ^ S_IFIFO) == 0)
			write(1, "|", 1);
		else if ((file->stat.st_mode & 0001) ||
				(file->stat.st_mode & 0010) ||
				(file->stat.st_mode & 0100))
			write(1, "*", 1);
	}
}

static void		ft_padding(int nb)
{
	while (nb > 0)
	{
		write(1, " ", 1);
		nb--;
	}
}

int				name_len(t_file *file, int flags)
{
	int ret;
	int mode;

	mode = file->stat.st_mode & 0xF000;
	ret = 0;
	ret += ft_strlen(file->d_name);
	if ((flags & 0b01000000))
	{
		if ((mode ^ S_IFDIR) == 0)
			ret += 1;
		else if ((mode ^ S_IFLNK) == 0)
			ret += 1;
		else if ((mode ^ S_IFSOCK) == 0)
			ret += 1;
		else if ((mode ^ S_IFIFO) == 0)
			ret += 1;
		else if ((file->stat.st_mode & 0001) ||
				(file->stat.st_mode & 0010) ||
				(file->stat.st_mode & 0100))
			ret += 1;
	}
	return (ret);
}

static void		ft_padding_name(t_nm *nm, int len_name, int *nb)
{
	if (nm->index > nm->col)
	{
		if (*nb < nm->nb_nm - 1)
			write(1, "\n", 1);
		nm->index = 0;
	}
	else
	{
		nm->index += nm->max;
		if (nm->index > nm->col)
		{
			if (*nb < nm->nb_nm - 1)
				write(1, "\n", 1);
			nm->index = 0;
		}
		else
		{
			if (*nb < nm->nb_nm - 1)
				ft_padding(nm->max - len_name + 2);
			nm->index -= nm->max;
		}
	}
}

void			ft_print_name(t_file *root, int flags, t_nm *nm)
{
	static int	nb;
	int			len_name;

	ft_name(root, flags);
	if (!(flags & 0b1000000000))
	{
		len_name = name_len(root, flags);
		nm->index += nm->max + 2;
		ft_padding_name(nm, len_name, &nb);
		if (nb == nm->nb_nm - 1)
		{
			write(1, "\n", 1);
			nb = 0;
			return ;
		}
		flags = (int)flags;
		nb++;
	}
	else
		write(1, "\n", 1);
}
