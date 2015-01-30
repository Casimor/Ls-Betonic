/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 17:08:45 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/30 15:55:20 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls(t_opt *opt, t_ldata *data)
{
	t_list		*f_lst;
	t_dirent	*dirent;
	size_t		i;
	t_files		*files;

	i = ft_lstsize(&(data)->file_lst);
	display_error(data);
	f_lst = data->file_lst;
	while (f_lst)
	{
		files = f_lst->content;
		while ((dirent = readdir(files->dir)))
		{
			ft_putchar('D');
			i = display(opt, new_info(dirent, files->name), files->name, i);
		}
		closedir(files->dir);
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
