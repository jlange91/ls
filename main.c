/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:20:27 by jlange            #+#    #+#             */
/*   Updated: 2017/01/06 22:20:15 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int ac, char **av)
{
	struct dirent *test;
	struct stat test2;
	DIR *ntm;

	if (av[1])
	{
		if ((ntm = opendir(av[1])) == NULL)
		{
			ft_printf("ntm salope\n");
		}
		else
		{
			while ((test = readdir(ntm)))
			{
				if(test->d_name[0] != '.')
					ft_printf("%s\n", test->d_name);
			}
			close(ntm);
		}
	}
}
