/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 19:11:54 by ochase            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2015/01/28 15:36:28 by bchevali         ###   ########.fr       */
=======
/*   Updated: 2015/01/28 17:36:04 by ochase           ###   ########.fr       */
>>>>>>> 089016a5518e7833014de10045d49b4e18436ab0
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <unistd.h>
# include <stdlib.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/dir.h>
# include <grp.h>
# include <pwd.h>
# include <time.h>
# include "libft.h"

# define SIX_MONTH 15552000

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

typedef int	(*t_cmp)(const t_info *, const t_info *, int);

char			*ft_permission(struct stat *cp);
t_info			*ft_new_info(t_dirent *dirent, char const *path);
void			ft_lstsort(t_list **list, const t_info *info, t_cmp c, int rev);
int				ft_cmp_lexico(const t_info *info1, const t_info *i, int rev);
int				ft_cmp_time(const t_info *info1, const t_info *info2, int rev);

t_list			*parser(char **args);

#endif
