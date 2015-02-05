/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 15:39:35 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/05 11:35:24 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// static void			apply_display_flag2(t_list **list, t_opt *opt)
// {
	// size_t			i;
	// const t_sort	flag_tab[] = {
		// {opt->f_flag, ft_f},
		// {opt->a_flag, ft_a}};
//
	// i = 0;
	// while (i < sizeof(flag_tab) / sizeof(t_sort))
	// {
		// if (flag_tab[i].flag == 0)
			// *list = flag_tab[i].f(*list);
		// i++;
	// }
// }

static void			apply_display_flag(t_list **list, t_opt *opt)
{
	size_t			i;
	const t_sort	flag_tab[] = {
		{opt->t_flag, ft_t},
		{opt->r_flag, ft_r}};
	const t_sort	iflag_tab[] = {
		{opt->f_flag, ft_f},
		{opt->a_flag, ft_a}};

	i = 0;
	if (opt->f_flag)
		opt->a_flag = 1;
	// apply_display_flag2(list, opt);
	while (i < sizeof(flag_tab) / sizeof(t_sort))
	{
		if (iflag_tab[i].flag == 0)
			*list = iflag_tab[i].f(*list);
		if (flag_tab[i].flag == 1)
			*list = flag_tab[i].f(*list);
		i++;
	}
}

static void			recursiv_display(t_opt *opt, t_list *list)
{
	t_list		*tmp;
	t_files		*files;
	DIR			*dir;

	get_dir_list(&list);
	tmp = list;
	while (tmp)
	{
		if ((dir = opendir(((t_info*)tmp->content)->path)))
		{
			files = create_tfiles(((t_info*)tmp->content)->path, dir);
			display(opt, files, 2, 1);
			closedir(dir);
			free(files);
		}
		tmp = tmp->next;
	}
}

void				display(t_opt *opt, t_files *files, size_t i, int is_recurs)
{
	t_list			*list;
	t_dirent		*dirent;

	list = NULL;
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
		ft_putchar('\n');
		recursiv_display(opt, list);
	}
	else
		ft_lstdel(&list, free_lst);
}
