/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:56:41 by jlange            #+#    #+#             */
/*   Updated: 2017/02/21 16:28:30 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static inline void		ft_colors4(t_file *file, int len, int mode, char *env)
{
	if (len > 17 && (file->stat.st_mode & S_ISGID) &&
			((file->stat.st_mode & 0001) ||
			(file->stat.st_mode & 0010) ||
			(file->stat.st_mode & 0100)))
	{
		ft_text_color(env[16]);
		ft_background_color(env[17]);
	}
	else if (len > 9 && ((file->stat.st_mode & 0001) ||
			(file->stat.st_mode & 0010) ||
			(file->stat.st_mode & 0100)))
	{
		ft_text_color(env[8]);
		ft_background_color(env[9]);
	}
	else if (len > 11 && (mode ^ S_IFBLK) == 0)
	{
		ft_text_color(env[10]);
		ft_background_color(env[11]);
	}
}

static inline void		ft_colors3(t_file *file, int len, int mode, char *env)
{
	if (len > 3 && (mode ^ S_IFLNK) == 0)
	{
		ft_text_color(env[2]);
		ft_background_color(env[3]);
	}
	else if (len > 5 && (mode ^ S_IFSOCK) == 0)
	{
		ft_text_color(env[4]);
		ft_background_color(env[5]);
	}
	else if (len > 15 && (file->stat.st_mode & S_ISUID) &&
			((file->stat.st_mode & 0001) ||
			(file->stat.st_mode & 0010) ||
			(file->stat.st_mode & 0100)))
	{
		ft_text_color(env[14]);
		ft_background_color(env[15]);
	}
	else
		ft_colors4(file, len, mode, env);
}

static inline void		ft_colors2(t_file *file, int len, int mode, char *env)
{
	if (len > 13 && (mode ^ S_IFCHR) == 0)
	{
		ft_text_color(env[12]);
		ft_background_color(env[13]);
	}
	else if (len > 7 && (mode ^ S_IFIFO) == 0)
	{
		ft_text_color(env[6]);
		ft_background_color(env[7]);
	}
	else if (len > 21 && (file->stat.st_mode & 02) && (mode ^ S_IFDIR) == 0)
	{
		ft_text_color(env[20]);
		ft_background_color(env[21]);
	}
	else if (len > 1 && (mode ^ S_IFDIR) == 0)
	{
		ft_text_color(env[0]);
		ft_background_color(env[1]);
	}
	else
		ft_colors3(file, len, mode, env);
}

void					ft_colors(t_file *file)
{
	int		j;
	int		mode;
	int		len;
	char	*env;

	env = getenv("LSCOLORS");
	mode = file->stat.st_mode & 0xF000;
	j = 9;
	len = (env == NULL) ? 0 : ft_strlen(env);
	if (len > 19 && (file->stat.st_mode & S_ISVTX) && (file->stat.st_mode & 02)
			&& (mode ^ S_IFDIR) == 0)
	{
		ft_text_color(env[18]);
		ft_background_color(env[19]);
	}
	else
		ft_colors2(file, len, mode, env);
	ft_putstr(file->d_name);
	ft_putstr(RESET);
}
