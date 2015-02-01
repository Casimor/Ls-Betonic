/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 17:08:45 by bchevali          #+#    #+#             */
/*   Updated: 2015/02/01 19:50:52 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls(t_opt *opt, t_ldata *data)
{
	t_list		*f_lst;
	t_files		*files;
	size_t		i;

	display_error(data);
	f_lst = data->file_lst;
	i = ft_lstsize(&f_lst);
	while (f_lst)
	{
		files = f_lst->content;
		display(opt, files, i);
		f_lst = f_lst->next;
	}
	ft_free_lst(&data->file_lst);
	ft_free_lst(&data->err_lst);
}
