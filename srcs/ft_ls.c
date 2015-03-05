/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 17:08:45 by bchevali          #+#    #+#             */
/*   Updated: 2015/02/24 20:58:54 by bboumend         ###   ########.fr       */
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
		if (!opt->re_flag && fi_lst->next)
			ft_putchar('\n');
		fi_lst = fi_lst->next;
	}
	ft_free_lst(&data->file_lst);
}
