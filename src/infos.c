/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:52:24 by jlange            #+#    #+#             */
/*   Updated: 2017/02/22 17:50:47 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static inline void	ft_tmp(char c, int *flags, int *error)
{
	(c == 'A') ? (*flags |= 0b10000000000) : (*error += 1);
	(c == '1') ? (*flags |= 0b01000000000) : (*error += 1);
	(c == 'o') ? (*flags |= 0b00100010000) : (*error += 1);
	(c == 'g') ? (*flags |= 0b00010010000) : (*error += 1);
	(c == 'F') ? (*flags |= 0b00001000000) : (*error += 1);
	(c == 'G') ? (*flags |= 0b00000100000) : (*error += 1);
	(c == 'l') ? (*flags |= 0b00000010000) : (*error += 1);
	(c == 'R') ? (*flags |= 0b00000001000) : (*error += 1);
	(c == 'a') ? (*flags |= 0b00000000100) : (*error += 1);
	(c == 'r') ? (*flags |= 0b00000000010) : (*error += 1);
	(c == 't') ? (*flags |= 0b00000000001) : (*error += 1);
	*flags &= (c == '1') ? 0b11111101111 : 0b11111111111;
	*error -= (c == '1') ? 1 : 0;
}

int					init_flags(char **av, int *flags)
{
	int j;
	int i;
	int error;

	j = 0;
	while (av[++j] && av[j][0] == '-')
	{
		if (av[j][0] == '-' && av[j][1] == '-' && av[j][2] == '\0')
			return (0);
		i = 0;
		while (av[j][++i])
		{
			error = 0;
			ft_tmp(av[j][i], flags, &error);
			if (error == 11)
				return (av[j][i]);
		}
	}
	return (0);
}

static inline void	ft_tmp2(char *name, int len)
{
	while (name[len])
		len++;
	while (len != -1 && name[len] != '/')
		len--;
	write(1, "ft_ls: ", 7);
	write(1, &name[len + 1], ft_strlen(&name[len + 1]));
	write(1, ": ", 2);
	ft_putstr(strerror(errno));
	write(1, "\n", 1);
}

int					count_folder(char *name, int flags)
{
	struct dirent	*dirent;
	DIR				*dir;
	int				len;
	struct stat		stat;

	len = 0;
	if ((dir = opendir(name)) == NULL)
	{
		if (errno != 20 && errno != 2)
			ft_tmp2(name, len);
		return (-1);
	}
	if ((flags & 0b10000))
	{
		lstat(name, &stat);
		if (((stat.st_mode & 0xF000) ^ S_IFLNK) == 0)
			return (-1);
	}
	while ((dirent = readdir(dir)))
		if (ft_check_file(dirent->d_name, flags) == 1)
			len++;
	closedir(dir);
	return (len);
}
