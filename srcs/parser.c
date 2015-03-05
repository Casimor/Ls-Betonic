/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 11:28:52 by ochase            #+#    #+#             */
/*   Updated: 2015/02/18 17:23:24 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		init_struct(t_opt **opt, t_ldata **data)
{
	ft_bzero(*opt, sizeof(t_opt));
	ft_bzero(*data, sizeof(t_data));
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

t_files			*create_tfiles(char *name, DIR *dir)
{
	t_files	*files;

	files = ft_memalloc(sizeof(t_files));
	if (!files)
		return (0);
	files->name = name;
	files->dir = dir;
	return (files);
}

void			parser(char **argv, t_opt *opt, t_ldata *data, t_list **f_lst)
{
	int		i;

	check_fts(argv);
	init_struct(&opt, &data);
	i = parse_opt(argv, opt);
	check_dir(argv, data, f_lst, i);
}
