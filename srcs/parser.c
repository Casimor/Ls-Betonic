/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 11:28:52 by ochase            #+#    #+#             */
/*   Updated: 2015/01/29 17:44:30 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

static void		parse_cmd(char *cmd, t_opt *opt)
{
	cmd++;
	while (*cmd)
	{
		if (!ft_strchr("lartR", *cmd))
			illegal_option_error(cmd);
		opt->l_flag |= (*cmd == 'l');
		opt->a_flag |= (*cmd == 'a');
		opt->r_flag |= (*cmd == 'r');
		opt->t_flag |= (*cmd == 't');
		opt->re_flag |= (*cmd == 'R');
		cmd++;
	}
}

static t_files	*create_tfiles(char *name, DIR *dir)
{
	t_files	*files;

	files = ft_memalloc(sizeof(t_files));
	if (!files)
		return (0);
	files->name = name;
	files->dir = dir;
	return (files);
}

static void		check_fts(char **argv)
{
	size_t	index;

	index = 1;
	while (argv[index])
	{
		if (ft_strlen(argv[index]) == 0)
			fts_error();
		index++;
	}
}

void			parser(char **argv, t_opt *opt, t_ldata *data)
{
	size_t	index;
	DIR		*dir;

	index = 1;
	ft_bzero(opt, sizeof(t_opt));
	ft_bzero(data, sizeof(t_data));
	dir = 0;
	check_fts(argv);
	while (argv[index] && argv[index][0] == '-')
		parse_cmd(argv[index++], opt);
	while (argv[index])
	{
		dir = opendir(argv[index]);
		if (dir)
			ft_lstpushback(&(data->file_lst),
				ft_lstnew(create_tfiles(argv[index], dir), sizeof(t_files)));
		else
			ft_lstpushback(&(data->err_lst),
				ft_lstnew(create_tfiles(argv[index], dir), sizeof(t_files)));
		index++;
	}
}
