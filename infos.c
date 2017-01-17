/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:52:24 by jlange            #+#    #+#             */
/*   Updated: 2017/01/17 17:07:57 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		init_flags(char **av, int *flags)
{
	int j;
	int i;
	int error;

	j = 0;
	while (av[++j] && av[j][0] == '-')
	{
		if (av[j][0] == '-' && av[j][1] == '-')
			return (0);
		i = 0;
		while (av[j][++i])
		{
			error = 0;
			(av[j][i] == 'l') ? (*flags |= 0b10000) : (error += 1);
			(av[j][i] == 'R') ? (*flags |= 0b01000) : (error += 1);
			(av[j][i] == 'a') ? (*flags |= 0b00100) : (error += 1);
			(av[j][i] == 'r') ? (*flags |= 0b00010) : (error += 1);
			(av[j][i] == 't') ? (*flags |= 0b00001) : (error += 1);
			*flags &= (av[j][i] == '1') ? 0b01111 : 0b11111;
			error -= (av[j][i] == '1') ? 1 : 0;
			if (error == 5)
				return (av[j][i]);
		}
	}
	return (0);
}

int		count_folder(char *name, int flags)
{
	struct dirent *dirent;
	DIR *dir;
	int len;

	len = 0;
	if ((dir = opendir(name)) == NULL)
	{
		perror("");
		return (-1);
	}
	while ((dirent = readdir(dir)))
		len++;
	closedir(dir);
	return (len);
}
