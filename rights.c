/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 17:27:02 by jlange            #+#    #+#             */
/*   Updated: 2017/01/18 17:31:22 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		file_type(struct stat stat)
{
	char type[] = "-dlbcp\0";
	int tab[] = {S_IFREG, S_IFDIR, S_IFLNK, S_IFBLK,S_IFCHR, S_IFIFO};
	int i;

	i = 0;
	while (tab[i] && ((stat.st_mode & 0xF000) ^ tab[i]) != 0)
		i++;
	ft_putchar(type[i]);
}

static void		rights_usr(struct stat stat)
{
	char type[9][4] = {"---", "r--", "-w-", "--x", "rw-", "r-x", "-wx", "rwx", 0};
	int tab[] = {00, 0400, 0200, 0100, 0600, 0500, 0300, 0700};
	int i;

	i = 0;
	while (((stat.st_mode & tab[i]) != (stat.st_mode & 0700)) && i != 8)
		i++;
	if (i != 8)
		ft_putstr(type[i]);
}

static void		rights_grp(struct stat stat)
{
	char type[9][4] = {"---", "r--", "-w-", "--x", "rw-", "r-x", "-wx", "rwx", 0};
	int tab[] = {00, 040, 020, 010, 060, 050, 030, 070};
	int i;

	i = 0;
	while (((stat.st_mode & tab[i]) != (stat.st_mode & 070)) && i != 8)
		i++;
	if (i != 8)
		ft_putstr(type[i]);
}

static void		rights_oth(struct stat stat)
{
	char type[9][4] = {"---", "r--", "-w-", "--x", "rw-", "r-x", "-wx", "rwx", 0};
	char type2[9][4] = {"---", "r--", "-w-", "--x", "rwT", "r-x", "-wx", "rwt", 0};
	int tab[] = {00, 04, 02, 01, 06, 05, 03, 07};
	int i;

	i = 0;
	while (((stat.st_mode & tab[i]) != (stat.st_mode & 07)) && i != 8)
		i++;
	if (i != 8 && stat.st_mode & 01000)
		ft_putstr(type2[i]);
	else if (i != 8)
		ft_putstr(type[i]);
}

void			print_rights(struct stat stat)
{
	file_type(stat);
	rights_usr(stat);
	rights_grp(stat);
	rights_oth(stat);
}
