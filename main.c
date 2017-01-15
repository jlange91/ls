/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:20:27 by jlange            #+#    #+#             */
/*   Updated: 2017/01/15 17:08:33 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <uuid/uuid.h>
#include <time.h>
#include <sys/types.h>

int main(int ac, char **av)
{
	struct dirent *test;
	DIR *ntm;

	if (av[1])
	{
		if ((ntm = opendir(av[1])) == NULL)
			write(1, "ntm salope\n", 11);
		else
		{
			while ((test = readdir(ntm)))
				if (test->d_name[0] != '.')
					ft_printf("%s\n", test->d_name);
			closedir(ntm);
		}
	}
}
/*
void	ft_test1(struct stat test)
{
	char type[] = "-dlbcp\0";
	int tab[] = {S_IFREG, S_IFDIR, S_IFLNK, S_IFBLK,S_IFCHR, S_IFIFO};
	int i;

	i = 0;
	while (tab[i] && ((test.st_mode & 0xF000) ^ tab[i]) != 0)
		i++;
	printf("%c", type[i]);
}

void	ft_test2(struct stat test)
{
	char type[9][4] = {"---", "r--", "-w-", "--x", "rw-", "r-x", "-wx", "rwx", 0};
	int tab[] = {00, 0400, 0200, 0100, 0600, 0500, 0300, 0700};
	int i;

	i = 0;
	while (((test.st_mode & tab[i]) != (test.st_mode & 0700)) && i != 8)
		i++;
	if (i != 8)
		printf("%s", type[i]);
}

void	ft_test3(struct stat test)
{
	char type[9][4] = {"---", "r--", "-w-", "--x", "rw-", "r-x", "-wx", "rwx", 0};
	int tab[] = {00, 040, 020, 010, 060, 050, 030, 070};
	int i;

	i = 0;
	while (((test.st_mode & tab[i]) != (test.st_mode & 070)) && i != 8)
		i++;
	if (i != 8)
		printf("%s", type[i]);
}

void	ft_test4(struct stat test)
{
	char type[9][4] = {"---", "r--", "-w-", "--x", "rw-", "r-x", "-wx", "rwx", 0};
	char type2[9][4] = {"---", "r--", "-w-", "--x", "rwT", "r-x", "-wx", "rwt", 0};
	int tab[] = {00, 04, 02, 01, 06, 05, 03, 07};
	int i;

	i = 0;
	while (((test.st_mode & tab[i]) != (test.st_mode & 07)) && i != 8)
		i++;
	if (i != 8 && test.st_mode & 01000)
		printf("%s", type2[i]);
	else if (i != 8)
		printf("%s", type[i]);
}

void	display_uid(uid_t test, gid_t lol)
{
	struct passwd *uid;
	struct group *grp;

	uid = getpwuid(test);
	grp = getgrgid(lol);
	printf("proprio : %s\ngroupe : %s\n", uid->pw_name, grp->gr_name);
}

int main(int ac, char **av)
{
	struct dirent *test;
	struct stat test2;
	DIR *ntm;

	if (av[1])
	{
		printf("nom : %s\n", av[1]);
		if (lstat(av[1], &test2))
			return (-1);
		printf("droits : ");
		ft_test1(test2);
		ft_test2(test2);
		ft_test3(test2);
		ft_test4(test2);
		printf("\nnombre de lien : %d\n", test2.st_nlink);
		display_uid(test2.st_uid, test2.st_gid);
		printf("taille : %lld octets\n", test2.st_size);
		if (((test2.st_mode & 0xF000) ^ S_IFBLK) == 0 ||
				((test2.st_mode & 0xF000) ^ S_IFCHR) == 0)
			printf("majeur : %d   mineur : %d", major(test2.st_rdev), minor(test2.st_rdev));
	}
}*/
