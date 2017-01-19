/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 17:27:02 by jlange            #+#    #+#             */
/*   Updated: 2017/01/19 17:05:35 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		file_type(struct stat stat)
{
	char	*type;
	int		tab[7];
	int		i;

	i = 0;
	type = "-dlbcp\0";
	tab[0] = S_IFREG;
	tab[1] = S_IFDIR;
	tab[2] = S_IFLNK;
	tab[3] = S_IFBLK;
	tab[4] = S_IFCHR;
	tab[5] = S_IFIFO;
	tab[6] = 0;
	while (tab[i] && ((stat.st_mode & 0xF000) ^ tab[i]) != 0)
		i++;
	ft_putchar(type[i]);
}

static void		rights_usr_grp(struct stat stat, int *tab)
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
	while (i != 8 && ((stat.st_mode & tab[i]) != (stat.st_mode & 0700)))
		i++;
	if (i != 8)
		ft_putstr(type[i]);
	i = -1;
	while (++i != 8)
		tab[i] >>= 3;
	i = 0;
	while (i != 8 && ((stat.st_mode & tab[i]) != (stat.st_mode & 070)))
		i++;
	if (i != 8)
		ft_putstr(type[i]);
}

static void		rights_oth1(struct stat stat, int *tab)
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
	while (((stat.st_mode & tab[i]) != (stat.st_mode & 07)) && i != 8)
		i++;
	if (i != 8)
		ft_putstr(type[i]);
}

static void		rights_oth2(struct stat stat, int *tab)
{
	char	type[8][4];
	int		i;

	i = 0;
	ft_strcpy(type[0], "---");
	ft_strcpy(type[1], "r--");
	ft_strcpy(type[2], "-w-");
	ft_strcpy(type[3], "--x");
	ft_strcpy(type[4], "rwT");
	ft_strcpy(type[5], "r-x");
	ft_strcpy(type[6], "-wx");
	ft_strcpy(type[7], "rwt");
	while (((stat.st_mode & tab[i]) != (stat.st_mode & 07)) && i != 8)
		i++;
	if (i != 8)
		ft_putstr(type[i]);
}

void			print_rights(struct stat stat)
{
	int i;
	int tab[8];

	i = 0;
	tab[0] = 00;
	tab[1] = 0400;
	tab[2] = 0200;
	tab[3] = 0100;
	tab[4] = 0600;
	tab[5] = 0500;
	tab[6] = 0300;
	tab[7] = 0700;
	file_type(stat);
	rights_usr_grp(stat, tab);
	while (++i != 8)
		tab[i] >>= 3;
	if ((stat.st_mode & 01000))
		rights_oth2(stat, tab);
	else
		rights_oth1(stat, tab);
}