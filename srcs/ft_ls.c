/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 17:08:45 by bchevali          #+#    #+#             */
/*   Updated: 2015/02/04 22:06:50 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls(t_opt *opt, t_ldata *data)
{
	t_list		*f_lst;
	t_files		*files;
	size_t		i;

	display_error(data);
	ft_free_lst(&data->err_lst);
	f_lst = data->file_lst;
	i = ft_lstsize(&f_lst);
	while (f_lst)
	{
		files = f_lst->content;
		display(opt, files, i, 0);
		f_lst = f_lst->next;
	}
	ft_lstdel(&data->file_lst, free_tfiles_lst);
}
