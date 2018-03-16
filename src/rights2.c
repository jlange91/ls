/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rights2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 18:12:21 by jlange            #+#    #+#             */
/*   Updated: 2017/02/12 18:13:36 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		rights_grp(struct stat stat, int *tab, char **buf)
{
	char	type[8][4];
	int		i;

	i = 0;
	ft_strcpy(type[0], "---");
	ft_strcpy(type[1], "r--");
	ft_strcpy(type[2], "-w-");
	ft_strcpy(type[3], "--x");
	ft_strcpy(type[4], "rw-");
	ft_strcpy(type[5], "r-x");
	ft_strcpy(type[6], "-wx");
	ft_strcpy(type[7], "rwx");
	while (i != 8 && ((stat.st_mode & tab[i]) != (stat.st_mode & 070)))
		i++;
	if (i != 8)
		ft_strcat_ls(buf, type[i]);
}

void		rights_grp2(struct stat stat, int *tab, char **buf)
{
	char	type[8][4];
	int		i;

	i = 0;
	ft_strcpy(type[0], "--S");
	ft_strcpy(type[1], "r-S");
	ft_strcpy(type[2], "-wS");
	ft_strcpy(type[3], "--s");
	ft_strcpy(type[4], "rwS");
	ft_strcpy(type[5], "r-s");
	ft_strcpy(type[6], "-ws");
	ft_strcpy(type[7], "rws");
	while (i != 8 && ((stat.st_mode & tab[i]) != (stat.st_mode & 070)))
		i++;
	if (i != 8)
		ft_strcat_ls(buf, type[i]);
}

void		rights_oth(struct stat stat, int *tab, char **buf)
{
	char	type[8][4];
	int		i;

	i = 0;
	ft_strcpy(type[0], "---");
	ft_strcpy(type[1], "r--");
	ft_strcpy(type[2], "-w-");
	ft_strcpy(type[3], "--x");
	ft_strcpy(type[4], "rw-");
	ft_strcpy(type[5], "r-x");
	ft_strcpy(type[6], "-wx");
	ft_strcpy(type[7], "rwx");
	while (i != 8 && ((stat.st_mode & tab[i]) != (stat.st_mode & 07)))
		i++;
	if (i != 8)
		ft_strcat_ls(buf, type[i]);
}

void		rights_oth2(struct stat stat, int *tab, char **buf)
{
	char	type[8][4];
	int		i;

	i = 0;
	ft_strcpy(type[0], "--T");
	ft_strcpy(type[1], "r-T");
	ft_strcpy(type[2], "-wT");
	ft_strcpy(type[3], "--t");
	ft_strcpy(type[4], "rwT");
	ft_strcpy(type[5], "r-t");
	ft_strcpy(type[6], "-wt");
	ft_strcpy(type[7], "rwt");
	while (i != 8 && ((stat.st_mode & tab[i]) != (stat.st_mode & 07)))
		i++;
	if (i != 8)
		ft_strcat_ls(buf, type[i]);
}
