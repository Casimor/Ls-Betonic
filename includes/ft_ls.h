/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 19:11:54 by ochase            #+#    #+#             */
/*   Updated: 2015/01/29 18:41:14 by bboumend         ###   ########.fr       */
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
	char	*mode;
	char	*link;
	char	*usr;
	char	*grp;
	char	*size;
	char	*time;
	char	*name;
	t_time	timesec;
}				t_info;

typedef struct	s_opt
{
	int		a_flag;
	int		r_flag;
	int		l_flag;
	int		t_flag;
	int		re_flag;
}				t_opt;

typedef struct	s_ldata
{
	t_list	*file_lst;
	t_list	*err_lst;
}				t_ldata;

typedef struct	s_files
{
	char	*name;
	DIR		*dir;
}				t_files;

typedef int	(*t_cmp)(const t_info *, const t_info *, int);

char			*ft_permission(struct stat *cp);
t_info			*ft_new_info(t_dirent *dirent, char const *path);
void			ft_lstsort(t_list **list, const t_info *info, t_cmp c, int rev);
int				ft_cmp_lexico(const t_info *info1, const t_info *i, int rev);
int				ft_cmp_time(const t_info *info1, const t_info *info2, int rev);

void			ft_print(t_opt *opt, t_list *list);
void			ft_ls(t_opt *opt, t_ldata *data);
void			display_error(t_ldata *data);

/*
** Parser
*/
void			parser(char **args, t_opt *opt, t_ldata *data);

/*
** Error
*/
void			illegal_option_error(char *cmd);
void			fts_error(void);

#endif
