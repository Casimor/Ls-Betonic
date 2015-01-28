/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/23 13:23:30 by bchevali          #+#    #+#             */
/*   Updated: 2014/10/01 14:25:10 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>

typedef struct	s_opt
{
	char	*str;
	void	(*f)(char **f_tab, char *opt);
}				t_opt;

char			**ft_ls(char *dir);
char			**ft_ls_sort(char **f_tab);
int				ft_readlen(char *dir);
void			ft_print(char **f_tab);
void			ft_printr_ls(char **f_tab, char *opt);
void			ft_print_ls(char **f_tab, char *opt);
int				ft_check_opt(char *line, char **f_tab);
int				ft_parse_flag(char *opt);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *str, int fd);
char			*ft_strdup(char *src);
void			ft_putendl(char *str);
int				ft_strcmp(char *s1, char *s2);
int				ft_strlen(char *str);

#endif
