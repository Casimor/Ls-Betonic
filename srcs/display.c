/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 15:39:35 by bboumend          #+#    #+#             */
/*   Updated: 2016/02/13 19:28:25 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			apply_display_flag(t_list **list, t_opt *opt, int ret)
{
	size_t			i;
	const t_sort	flag_tab[] = { \
	{opt->f_flag, ft_f, 0}, \
	{opt->a_flag, ft_a, 0}, \
	{opt->t_flag, ft_t, 1}, \
	{opt->r_flag, ft_r, 1}};

	i = 0;
	if (ret > 0)
		return ;
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

static void			recursiv_open(DIR *dir, t_opt *opt, char *path, t_ldata *dt)
{
	t_files		*files;

	files = create_tfiles(path, dir);
	ft_putchar('\n');
	ft_putstr(files->name);
	ft_putendl(":");
	display(opt, files, dt, 1);
	closedir(dir);
	free(files);
}

static void			recursiv_display(t_opt *opt, t_list *list, t_ldata *data)
{
	t_list		*tmp;
	t_list		*err_lst;
	DIR			*dir;

	get_dir_list(&list);
	tmp = list;
	err_lst = NULL;
	while (tmp)
	{
		if ((dir = opendir(((t_info*)tmp->content)->path)))
			recursiv_open(dir, opt, ((t_info*)tmp->content)->path, data);
		else
		{
			ft_putchar('\n');
			ft_putstr(((t_info*)tmp->content)->path);
			ft_putendl(":");
			ft_lstadd(&err_lst, ft_lstnew(\
							create_tfiles(((t_info*)tmp->content)->name, dir), \
							sizeof(t_files)));
			display_error(err_lst);
			free(err_lst);
			err_lst = NULL;
		}
		tmp = tmp->next;
	}
}

void				display(t_opt *opt, t_files *files, t_ldata *dt, int is_rec)
{
	t_list			*list;
	t_dirent		*dirent;
	int				ret;

	ret = 0;
	list = NULL;
	(void)is_rec;
	while ((dirent = readdir(files->dir)))
		ret += lstaddinfo(&list, new_info(dirent, files->name), dirent, opt);
	apply_display_flag(&list, opt, ret);
	if (ret > 0)
		print_perm_denied(list, files->name, dt);
	else
	{
		ft_print(opt, list, files->name, dt);
		if (opt->re_flag)
			recursiv_display(opt, list, dt);
		else
			ft_lstdel(&list, free_lst);
	}
}
