/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 16:06:21 by jlange            #+#    #+#             */
/*   Updated: 2017/02/21 17:32:46 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static inline void		colors_l4(t_file *file, int len, char *env, char **buf)
{
	if (len > 17 && (file->stat.st_mode & S_ISGID) &&
			((file->stat.st_mode & 0001) ||
			(file->stat.st_mode & 0010) ||
			(file->stat.st_mode & 0100)))
	{
		ft_text_color_l(env[16], buf);
		ft_background_color_l(env[17], buf);
	}
	else if (len > 9 && ((file->stat.st_mode & 0001) ||
			(file->stat.st_mode & 0010) ||
			(file->stat.st_mode & 0100)))
	{
		ft_text_color_l(env[8], buf);
		ft_background_color_l(env[9], buf);
	}
	else if (len > 11 && ((file->stat.st_mode & 0xF000) ^ S_IFBLK) == 0)
	{
		ft_text_color_l(env[10], buf);
		ft_background_color_l(env[11], buf);
	}
}

static inline void		colors_l3(t_file *file, int len, char *env, char **buf)
{
	if (len > 3 && ((file->stat.st_mode & 0xF000) ^ S_IFLNK) == 0)
	{
		ft_text_color_l(env[2], buf);
		ft_background_color_l(env[3], buf);
	}
	else if (len > 5 && ((file->stat.st_mode & 0xF000) ^ S_IFSOCK) == 0)
	{
		ft_text_color_l(env[4], buf);
		ft_background_color_l(env[5], buf);
	}
	else if (len > 15 && (file->stat.st_mode & S_ISUID) &&
			((file->stat.st_mode & 0001) ||
			(file->stat.st_mode & 0010) ||
			(file->stat.st_mode & 0100)))
	{
		ft_text_color_l(env[14], buf);
		ft_background_color_l(env[15], buf);
	}
	else
		colors_l4(file, len, env, buf);
}

static inline void		colors_l2(t_file *file, int len, char *env, char **buf)
{
	if (len > 13 && ((file->stat.st_mode & 0xF000) ^ S_IFCHR) == 0)
	{
		ft_text_color_l(env[12], buf);
		ft_background_color_l(env[13], buf);
	}
	else if (len > 7 && ((file->stat.st_mode & 0xF000) ^ S_IFIFO) == 0)
	{
		ft_text_color_l(env[6], buf);
		ft_background_color_l(env[7], buf);
	}
	else if (len > 21 && (file->stat.st_mode & 02) &&
			((file->stat.st_mode & 0xF000) ^ S_IFDIR) == 0)
	{
		ft_text_color_l(env[20], buf);
		ft_background_color_l(env[21], buf);
	}
	else if (len > 1 && ((file->stat.st_mode & 0xF000) ^ S_IFDIR) == 0)
	{
		ft_text_color_l(env[0], buf);
		ft_background_color_l(env[1], buf);
	}
	else
		colors_l3(file, len, env, buf);
}

void					ft_colors_l(t_file *file, char **buf)
{
	int		j;
	int		len;
	char	*env;

	env = getenv("LSCOLORS");
	j = 9;
	len = (env == NULL) ? 0 : ft_strlen(env);
	if (len > 19 && (file->stat.st_mode & S_ISVTX) && (file->stat.st_mode & 02)
			&& ((file->stat.st_mode & 0xF000) ^ S_IFDIR) == 0)
	{
		ft_text_color_l(env[18], buf);
		ft_background_color_l(env[19], buf);
	}
	else
		colors_l2(file, len, env, buf);
}
