/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 17:08:45 by bchevali          #+#    #+#             */
/*   Updated: 2015/02/18 14:46:47 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls(t_opt *opt, t_ldata *data, t_list *f_lst)
{
	t_list		*fi_lst;
	t_files		*files;
	size_t		i;

	display_error(data->err_lst);
	print_files(f_lst, data);
	ft_free_lst(&data->err_lst);
	fi_lst = data->file_lst;
	i = ft_lstsize(&fi_lst);
	if (f_lst)
		i++;
	while (fi_lst)
	{
		files = fi_lst->content;
		display(opt, files, i, 0);
		fi_lst = fi_lst->next;
	}
	ft_free_lst(&data->file_lst);
}
