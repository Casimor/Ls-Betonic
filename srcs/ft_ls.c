/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 17:08:45 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/29 19:29:07 by bchevali         ###   ########.fr       */
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
}
