/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 17:08:45 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/28 19:36:09 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

int		ft_ls(char *arg, t_opt *opt, size_t nb_dir)
{
	t_dirent	*dirent;
	DIR			*dir;
	t_list		*list;
	t_info		*info;

	list = NULL;
	if ((dir = opendir(arg)))
	{
		(void)nb_dir;
		while ((dirent = readdir(dir)))
		{
			info = ft_new_info(dirent, arg);
			ft_lstsort(&list, info, ft_cmp_lexico, 0);
			// if (nb_dir > 1)
			// {
			// 	ft_putstr(dirent->d_name);
			// 	ft_putendl(":");
			// }
			ft_print(opt, list);
		}
		closedir (dir);
	}
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
	return (1);
}
