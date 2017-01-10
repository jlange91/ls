/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:20:27 by jlange            #+#    #+#             */
/*   Updated: 2017/01/10 22:28:44 by jlange           ###   ########.fr       */
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

/*int main(int ac, char **av)
{
	struct dirent *test;
	struct stat test2;
	DIR *ntm;

	if (av[1])
	{
		if ((ntm = opendir(av[1])) == NULL)
		{
			write(1, "ntm salope\n", 11);
		}
		else
		{
			while ((test = readdir(ntm)))
			{
				if(test->d_name[0] != '.')
				{
					ft_printf("%s   ", test->d_name);
					ft_printf("%d    ", stat(test->d_name, &test2));
					ft_printf("%d\n", test2.st_flags);
				}
			}
			closedir(ntm);
		}
	}
}*/

void	ft_test1(struct stat test)
{
	char type[] = "-dbl\0";
	int tab[] = {S_IFREG, S_IFDIR, S_IFBLK, S_IFLNK};
	int i;

	i = 0;
	while ((test.st_mode & tab[i]) != (test.st_mode & 0xF000))
		i++;
	printf("%c", type[i]);
}

void	ft_test2(struct stat test)
{
	char type[8][4] = {"---", "r--", "-w-", "--x", "rw-", "r-x", "-wx", "rwx"};
	int tab[] = {0b0, 0b100000000, 0b010000000, 0b001000000, 0b110000000,
		0b101000000, 0b011000000, 0b111000000};
	int i;

	i = 0;
	while (((test.st_mode & tab[i]) != (test.st_mode & 0b111000000)) && i != 8)
		i++;
	if (i != 8)
		printf("%s", type[i]);
}

void	ft_test3(struct stat test)
{
	char type[8][4] = {"---", "r--", "-w-", "--x", "rw-", "r-x", "-wx", "rwx"};
	int tab[] = {0b0, 0b100000, 0b010000, 0b001000, 0b110000, 0b101000,
		0b011000, 0b111000};
	int i;

	i = 0;
	while (((test.st_mode & tab[i]) != (test.st_mode & 0b111000)) && i != 8)
		i++;
	if (i != 8)
		printf("%s", type[i]);
}

void	ft_test4(struct stat test)
{
	char type[8][4] = {"---", "r--", "-w-", "--x", "rw-", "r-x", "-wx", "rwx"};
	int tab[] = {0b0, 0b100, 0b010, 0b001, 0b110, 0b101, 0b011, 0b111};
	int i;

	i = 0;
	while (((test.st_mode & tab[i]) != (test.st_mode & 0b111)) && i != 8)
		i++;
	if (i != 8)
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
	}
}

/*int main(int ac, char **av)
{

	return (0);
}*/
