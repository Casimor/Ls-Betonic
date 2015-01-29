/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 17:08:45 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/29 16:42:07 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

void	ft_ls(t_opt *opt, t_ldata *data)
{
	t_list		*f_lst;
	// t_dirent	*dirent;
	// t_info		*info;
	// t_list		*list;

	(void)opt;
	// list = NULL;
	f_lst = data->file_lst;
	while (f_lst)
	{
		t_files	*files = f_lst->content;
		ft_putstr(files->name);
		// while ((dirent = readdir(files->dir)))
		// {
		// 	info = ft_new_info(dirent, files->name);
		// 	ft_lstsort(&list, info, ft_cmp_lexico, 0);
		// 	ft_putendl(dirent->d_name);
		// }
		f_lst = f_lst->next;
	}
}

	// t_dirent	*dirent;
	// DIR			*dir;
	// t_list		*list;
	// t_info		*info;

	// (void)opt;
	// list = NULL;
	// if ((dir = opendir(arg)))
	// {
		// while ((dirent = readdir(dir)))
		// {
		// }
		// ft_print(opt, list);
		// closedir (dir);
	// }
	// while (list)
	// {
	// 	ft_putstr(((t_info *)(list->content))->mode);
	// 	ft_putchar('\t');
	// 	ft_putstr(((t_info *)(list->content))->link);
	// 	ft_putchar('\t');
	// 	ft_putstr(((t_info *)(list->content))->usr);
	// 	ft_putchar('\t');
	// 	ft_putstr(((t_info *)(list->content))->grp);
	// 	ft_putchar('\t');
	// 	ft_putstr(((t_info *)(list->content))->size);
	// 	ft_putchar('\t');
	// 	ft_putstr(((t_info *)(list->content))->time);
	// 	ft_putchar('\t');
	// 	ft_putstr(((t_info *)(list->content))->name);
	// 	ft_putchar('\n');
	// 	list = list->next;
	// }
	// return (1);
// }
