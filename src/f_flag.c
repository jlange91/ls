/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   F_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:17:39 by jlange            #+#    #+#             */
/*   Updated: 2017/02/21 18:22:53 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_flag_f(t_file *file, char **buf)
{
	int mode;

	mode = file->stat.st_mode & 0xF000;
	if ((mode ^ S_IFDIR) == 0)
		ft_charcat(buf, '/');
	else if ((mode ^ S_IFLNK) == 0)
		ft_charcat(buf, '@');
	else if ((mode ^ S_IFSOCK) == 0)
		ft_charcat(buf, '=');
	else if ((mode ^ S_IFIFO) == 0)
		ft_charcat(buf, '|');
	else if ((file->stat.st_mode & 0001) ||
			(file->stat.st_mode & 0010) ||
			(file->stat.st_mode & 0100))
		ft_charcat(buf, '*');
}
