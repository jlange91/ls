/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:36:16 by jlange            #+#    #+#             */
/*   Updated: 2017/02/22 17:49:26 by jlange           ###   ########.fr       */
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
# include <sys/ioctl.h>

# define LNK_BUFF_SIZE 1024
# define L_BUFF_SIZE 2048

# define BACK_BLACK   "\x1b[40m"
# define BACK_RED     "\x1b[41m"
# define BACK_GREEN   "\x1b[42m"
# define BACK_YELLOW  "\x1b[43m"
# define BACK_BLUE    "\x1b[44m"
# define BACK_MAGENTA "\x1b[45m"
# define BACK_CYAN    "\x1b[46m"
# define BACK_GREY    "\x1b[47m"

# define BLACK        "\033[30m"
# define RED          "\033[31m"
# define GREEN        "\033[32m"
# define BROWN        "\033[33m"
# define BLUE         "\033[34m"
# define MAGENTA      "\033[35m"
# define CYAN         "\033[36m"
# define GREY         "\033[37m"

# define D_GREY       "\033[1m\033[30m"
# define B_RED        "\033[1m\033[31m"
# define B_GREEN      "\033[1m\033[32m"
# define YELLOW       "\033[1m\033[33m"
# define B_BLUE       "\033[1m\033[34m"
# define B_MAGENTA    "\033[1m\033[35m"
# define B_CYAN       "\033[1m\033[36m"
# define WHITE        "\033[1m\033[37m"

# define RESET        "\033[0m"
# define NORME        (file->stat.st_mode & 0xF000)

typedef struct		s_file
{
	char			*d_name;
	struct dirent	*dirent;
	struct stat		stat;
	struct passwd	*uid;
	struct group	*grp;
	char			*buf;
	char			*path;
	int				major;
	int				minor;
	struct s_file	*left;
	struct s_file	*right;
}					t_file;

typedef struct		s_len
{
	int		lnk;
	int		uid;
	int		grp;
	int		size;
	int		major;
	int		minor;
	int		total;
}					t_len;

typedef struct		s_nm
{
	int		index;
	int		max;
	int		nb_nm;
	int		col;
	int		row;
}					t_nm;

typedef struct		s_display
{
	int		j;
	int		k;
	int		i;
	t_nm	nm;
}					t_display;

typedef struct		s_display_l
{
	int		j;
	int		k;
	int		i;
	t_len	len;
	DIR		*dir;
}					t_display_l;

typedef struct		s_print_l
{
	char	*buf;
	t_len	len_arg;
	char	*strtime;
	char	*tmp;
	long	timenow;
	t_len	len;
}					t_print_l;

int					init_flags(char **av, int *flags);
void				free_tab(t_file *file);
int					display_one_file(char **av, int ac, int flags, int i);
int					display_one_file_l(char **av, int ac, int flags, int i);
void				ft_print_name(t_file *root, int flags, t_nm *nm);
void				fill_info_file_l(char *name, int nb_file, int flags);
void				fill_info_file(char *name, int nb_file, int flags);
void				ft_error(char *name);
void				ft_tri_arg(char **av, int flags);
void				ft_tri_arg_time(char **av, int flags, int nb);
void				init_fill_three(t_file *neww, t_file *root, int flags);
void				print_three(t_file *root, int flags, t_nm *nm);
void				print_three_l(t_file *root, int flags, t_len len);
void				print_reverse_three(t_file *root, int flags, t_nm *nm);
void				print_reverse_three_l(t_file *root, int flags, t_len len);
int					count_folder(char *name, int flags);
void				init_struct_file(char *name, int flags);
void				print_rights(struct stat stat, char **buf);
void				ft_recursive(t_file *root, int flags, char *name);
void				ft_reverse_recursive(t_file *root, int flags, char *name);
char				*ft_add_prefix(char *s1, char *s2);
void				add_padding(char **s1, int nb);
void				ft_charcat(char **s1, const char s2);
void				ft_strcat_ls(char **s1, const char *s2);
void				ft_strncat_ls(char **s1, const char *s2, int nb);
void				ft_strnncat_ls(char **s1, const char *s2, int nb1, int nb2);
void				ft_add_name(char **s1, const char *s2, t_file *file,
		int flags);
void				ft_print_lflag(t_file *root, t_len len, int flags);
void				free_ls(t_file *root);
void				ft_itoa_ls(uintmax_t n, char *buf);
void				ft_print_lnk(t_file *root, char **buf);
void				ft_nb_lnk(t_file *root, char *buf, t_len *len_arg,
		t_len len);
void				ft_acl(t_file *root, char **buf, t_len *len_arg);
void				print_flag_f(t_file *file, char **buf);
void				rights_grp(struct stat stat, int *tab, char **buf);
void				rights_grp2(struct stat stat, int *tab, char **buf);
void				rights_oth(struct stat stat, int *tab, char **buf);
void				rights_oth2(struct stat stat, int *tab, char **buf);
void				ft_colors(t_file *file);
void				ft_text_color(char c);
void				ft_background_color(char c);
void				ft_text_color_l(char c, char **buf);
void				ft_background_color_l(char c, char **buf);
void				ft_colors_l(t_file *file, char **buf);
void				ft_display_l(t_file *file, t_len len, int flags);
int					ft_check_file(char *name, int flags);

#endif
