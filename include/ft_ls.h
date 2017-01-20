/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:36:16 by jlange            #+#    #+#             */
/*   Updated: 2017/01/20 21:03:03 by jlange           ###   ########.fr       */
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
# include <sys/acl.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <time.h>
# include <errno.h>
# include "../libft/includes/libft.h"
# include <sys/xattr.h>

typedef struct		s_folder
{
	char	*name;
	int		nb_file;
}					t_folder;

typedef struct		s_file
{
	char			*d_name;
	struct dirent	*dirent;
	struct stat		stat;
	struct passwd	*uid;
	struct group	*grp;
	char			*buf;
	struct s_file	*left;
	struct s_file	*right;
	char			*path;
}					t_file;

typedef struct		s_len
{
	int		lnk;
	int		uid;
	int		grp;
	int		size;
}					t_len;

int		init_flags(char **av, int *flags);
void	fill_three(t_file *neww, t_file *root);
void	fill_three_time(t_file *neww, t_file *root);
void	ft_print_three(t_file *root, int flags);
void	ft_print_reverse_three(t_file *root, int flags);
int		count_folder(char *name, int flags);
int		init_struct_file(char *name, int flags);
void	print_rights(struct stat stat, char **buf);
void	ft_recursive(t_file *root, int flags, char *name);
void	ft_reverse_recursive(t_file *root, int flags, char *name);
char	*ft_add_prefix(char *s1, char *s2);
void	ft_charcat(char **s1, const char s2);
void	ft_strcat_ls(char **s1, const char *s2);
void	ft_add_name(char **s1, const char *s2);
void	ft_print_lflag(t_file *root);

#endif
