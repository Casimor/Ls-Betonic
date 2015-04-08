/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 17:08:45 by bchevali          #+#    #+#             */
/*   Updated: 2015/03/10 16:05:11 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls(t_opt *opt, t_ldata *data, t_list *f_lst)
{
	t_list		*fi_lst;
	t_files		*files;

	display_error(data->err_lst);
	print_files(f_lst, data);
	ft_free_lst(&data->err_lst);
	fi_lst = data->file_lst;
	data->nb_file = ft_lstsize(&fi_lst);
	data->nb_dir = data->nb_file;
	if (f_lst)
		data->nb_file++;
	while (fi_lst)
	{
		files = fi_lst->content;
		display(opt, files, data, 0);
		if (!opt->re_flag && fi_lst->next)
			ft_putchar('\n');
		fi_lst = fi_lst->next;
	}
	ft_free_lst(&data->file_lst);
}
