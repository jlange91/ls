/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:36:16 by jlange            #+#    #+#             */
/*   Updated: 2017/01/15 21:29:37 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <time.h>

typedef struct		s_folder
{
	char	*name;
	int		nb_file;
}					t_folder;

typedef struct		s_file
{
	struct dirent	*dirent;
	struct stat		stat;
	struct passwd	*uid;
	struct group	*grp;
	char			*buf;
	struct s_file	*left;
	struct s_file	*right;
}					t_file;

#endif
