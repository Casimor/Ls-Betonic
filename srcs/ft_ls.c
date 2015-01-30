/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 17:08:45 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/30 13:48:59 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls(t_opt *opt, t_ldata *data)
{
	t_list		*f_lst;
	t_dirent	*dirent;
	t_info		*info;
	t_list		*list;
	size_t		i;

	i = ft_lstsize(&(data)->file_lst);
	display_error(data);
	f_lst = data->file_lst;
	while (f_lst)
	{
		list = NULL;
		t_files	*files = f_lst->content;
		while ((dirent = readdir(files->dir)))
		{
			info = new_info(dirent, files->name);
			ft_lstsort(&list, info, ft_cmp_lexico, 0);
		}
		closedir(files->dir);
		i = ft_print(opt, list, files->name, i) + 1;
		f_lst = f_lst->next;
	}
	// while (list)
	// {
	// 	ft_putnbr(((t_info *)(list->content))->blocks);
	// 	ft_putstr(((t_info *)(list->content))->name);
	// 	ft_putchar('\n');
	// 	list = list->next;
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
}
