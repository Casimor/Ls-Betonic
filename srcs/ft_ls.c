/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 17:08:45 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/30 15:48:47 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls(t_opt *opt, t_ldata *data)
{
	t_list		*f_lst;
	t_dirent	*dirent;
	t_list		*list;
	size_t		i;
	t_files		*files;

	i = ft_lstsize(&(data)->file_lst);
	display_error(data);
	f_lst = data->file_lst;
	while (f_lst)
	{
		list = NULL;
		files = f_lst->content;
		while ((dit = readdir(files->dir)))
		{
			if (opt->t_flag == 1)
				ft_lstsort(&list, new_info(dit, files->name), ft_cmp_time, 0);
			else
				ft_lstsort(&list, new_info(dit, files->name), ft_cmp_lexico, 0);
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
