/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 16:39:22 by bchevali          #+#    #+#             */
/*   Updated: 2015/02/18 18:08:56 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		parse_cmd(char cmd, t_opt *opt)
{
	opt->l_flag |= (cmd == 'l');
	opt->a_flag |= (cmd == 'a');
	opt->r_flag |= (cmd == 'r');
	opt->t_flag |= (cmd == 't');
	opt->re_flag |= (cmd == 'R');
	opt->f_flag |= (cmd == 'f');
	opt->g_flag |= (cmd == 'g');
	if (!ft_strchr("lartRfg", cmd))
		illegal_option_error(cmd);
	return (0);
}

int				parse_opt(char **av, t_opt *opt)
{
	int		i;
	int		j;

	i = 1;
	while (av[i] && av[i][0] == '-' && ft_strlen(av[i]) > 1)
	{
		if (!ft_strcmp(av[i], "--"))
			return (i + 1);
		j = 1;
		while (av[i][j])
		{
			parse_cmd(av[i][j], opt);
			j++;
		}
		i++;
	}
	return (i);
}

void			check_dir(char **av, t_ldata *data, t_list **f_lst, int i)
{
	t_stat	fstat;
	DIR		*dir;

	dir = 0;
	while (av[i])
	{
		dir = opendir(av[i]);
		if (dir)
			ft_lstpushback(&(data->file_lst),
				ft_lstnew(create_tfiles(av[i], dir), sizeof(t_files)));
		else if (stat(av[i], &fstat) == 0)
		{
			if (S_ISREG(fstat.st_mode))
				add_files(av[i], f_lst);
			else
				ft_lstpushback(&(data->err_lst),
					ft_lstnew(create_tfiles(av[i], dir), sizeof(t_files)));
		}
		else
			ft_lstpushback(&(data->err_lst),
				ft_lstnew(create_tfiles(av[i], dir), sizeof(t_files)));
		i++;
	}
}
