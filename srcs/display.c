/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 15:39:35 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/11 19:31:12 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			apply_display_flag(t_list **list, t_opt *opt)
{
	size_t			i;
	const t_sort	flag_tab[] =

	{ \
	{opt->f_flag, ft_f, 0}, \
	{opt->a_flag, ft_a, 0}, \
	{opt->t_flag, ft_t, 1}, \
	{opt->r_flag, ft_r, 1}};
	i = 0;
	if (opt->f_flag == flag_tab[0].flag_check)
	{
		while (i < sizeof(flag_tab) / sizeof(t_sort))
		{
			if (flag_tab[i].flag == flag_tab[i].flag_check)
				*list = flag_tab[i].f(*list);
			i++;
		}
	}
}

static void			recursiv_display(t_opt *opt, t_list *list)
{
	t_list		*tmp;
	t_list		*err_lst;
	t_files		*files;
	DIR			*dir;

	get_dir_list(&list);
	tmp = list;
	err_lst = NULL;
	while (tmp)
	{
		if ((dir = opendir(((t_info*)tmp->content)->path)))
		{
			files = create_tfiles(((t_info*)tmp->content)->path, dir);
			display(opt, files, 2, 1);
			closedir(dir);
			free(files);
		}
		else
			ft_lstadd(&err_lst, ft_lstnew( \
							create_tfiles(((t_info*)tmp->content)->path, dir), \
							sizeof(t_files)));
		tmp = tmp->next;
	}
	display_error(err_lst);
}

void				display(t_opt *opt, t_files *files, size_t i, int is_recurs)
{
	t_list			*list;
	t_dirent		*dirent;

	list = NULL;
	if (opt->re_flag == 1)
		opt->a_flag = 1;
	while ((dirent = readdir(files->dir)))
	{
		if (is_recurs && (!ft_strcmp(dirent->d_name, ".") ||
							!ft_strcmp(dirent->d_name, "..")))
			continue ;
		lstaddinfo(&list, new_info(dirent, files->name));
	}
	apply_display_flag(&list, opt);
	ft_print(opt, list, files->name, i);
	if (opt->re_flag)
	{
		if (list)
			ft_putchar('\n');
		recursiv_display(opt, list);
	}
	else
		ft_lstdel(&list, free_lst);
}
