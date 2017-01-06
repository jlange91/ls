/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:20:27 by jlange            #+#    #+#             */
/*   Updated: 2017/01/06 18:40:17 by jlange           ###   ########.fr       */
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

	if ((ntm = opendir("/dev")) == NULL)
	{
		ft_printf("ntm salope\n");
	}
	while ((test = readdir(ntm)))
	{
		ft_printf("%s\n", test->d_name);
	}
	close(ntm);
}
