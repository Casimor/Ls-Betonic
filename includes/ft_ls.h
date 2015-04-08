/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 19:11:54 by ochase            #+#    #+#             */
/*   Updated: 2015/03/10 16:03:36 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdlib.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/dir.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <grp.h>
# include <pwd.h>
# include <time.h>
# include <stdio.h>
# include "libft.h"

# define SIX_MONTHS 15552000

typedef struct passwd	t_passwd;
typedef struct group	t_group;
typedef struct timespec	t_time;
typedef struct stat		t_stat;
typedef struct dirent	t_dirent;

typedef struct	s_info
{
	char		*mode;
	char		*link;
	char		*usr;
	char		*grp;
	char		*size;
	char		*time;
	char		*name;
	t_time		timesec;
	blkcnt_t	blocks;
	char		*path;
	char		*link_info;
}				t_info;

typedef struct	s_opt
{
	int		a_flag;
	int		r_flag;
	int		l_flag;
	int		t_flag;
	int		re_flag;
	int		f_flag;
	int		g_flag;
}				t_opt;

typedef struct	s_ldata
{
	t_list	*file_lst;
	t_list	*err_lst;
	size_t	nb_file;
	size_t	nb_dir;
}				t_ldata;

typedef struct	s_files
{
	char	*name;
	DIR		*dir;
}				t_files;

typedef struct	s_bit
{
	mode_t	bit;
	char	ret;
}				t_bit;

typedef struct	s_size
{
	size_t	mode;
	size_t	link;
	size_t	user;
	size_t	group;
	size_t	fsize;
	size_t	minor;
	size_t	major;
}				t_size;

typedef int	(*t_cmp)(const t_info *, const t_info *, int);

void			lstsort(t_list **list, t_cmp cmp, int rev);
int				lstaddinfo(t_list **l, const t_info *i, t_dirent *d, t_opt *o);
int				cmp_lexico(const t_info *info1, const t_info *i, int rev);
int				cmp_time(const t_info *info1, const t_info *info2, int rev);
int				cmp_files(const t_info *file_1, const t_info *file_2, int rev);
void			print_files(t_list *files, t_ldata *data);
void			add_files(char *name, t_list **f_lst);

void			ft_print(t_opt *opt, t_list *list, char *name, t_ldata *data);
void			ft_ls(t_opt *opt, t_ldata *data, t_list *f_lst);

/*
** Display
*/
void			display(t_opt *opt, t_files *files, t_ldata *dt, int is_recurs);
void			display_error(t_list *err_lst);

/*
** Option -l
*/
char			*permissions(struct stat *cp, char *path);
t_info			*new_info(t_dirent *dirent, char const *path);
char			*get_link_infos(char const *path);
void			print_lopt(t_list *list);
void			set_padding_nbr(char *content, size_t size);
void			set_padding(char *content, size_t size, size_t end_space);
void			set_padding_major_minor(char *content, t_size *max);
char			*get_size(t_stat *stat, char *mode);
void			handle_size(t_list *list, t_size *max);
char			third_mode(int cond1, int cond2, char first, char second);

/*
** Option -g
*/
void			print_gopt(t_list *list);

/*
** Sort tools
*/
typedef struct	s_sort
{
	int			flag;
	t_list		*(*f)(t_list *list);
	int			flag_check;
}				t_sort;

t_list			*ft_r(t_list *list);
t_list			*ft_t(t_list *list);
t_list			*ft_a(t_list *list);
t_list			*ft_f(t_list *list);

/*
** Recursiv tools
*/
void			get_dir_list(t_list **list);
void			free_lst(void *lst, size_t i);

/*
** Parser
*/
void			parser(char **args, t_opt *opt, t_ldata *data, t_list **files);
t_files			*create_tfiles(char *name, DIR *dir);
int				parse_opt(char **av, t_opt *opt);
void			check_dir(char **av, t_ldata *data, t_list **f_lst, int i);

/*
** Error
*/
void			sort_lst(t_list *err_lst);
void			illegal_option_error(char cmd);
void			fts_error(void);
int				perm_denied(t_list **list, char *name, t_opt *opt);
void			print_perm_denied(t_list *list, char *name, t_ldata *data);

#endif
