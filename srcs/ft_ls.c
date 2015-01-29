/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 17:08:45 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/29 18:41:39 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls(t_opt *opt, t_ldata *data)
{
	t_list		*f_lst;
	t_dirent	*dirent;
	t_info		*info;
	t_list		*list;

	(void)opt;
	display_error(data);
	f_lst = data->file_lst;
	while (f_lst)
	{
		list = NULL;
		t_files	*files = f_lst->content;
		while ((dirent = readdir(files->dir)))
		{
			info = ft_new_info(dirent, files->name);
			ft_lstsort(&list, info, ft_cmp_lexico, 0);
		}
		closedir(files->dir);
		ft_print(opt, list);
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
