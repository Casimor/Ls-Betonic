/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 15:01:57 by ochase            #+#    #+#             */
/*   Updated: 2015/02/17 19:59:30 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	t_opt	opt;
	t_ldata	data;
	t_list	*f_lst;

	(void)argc;
	f_lst = 0;
	parser(argv, &opt, &data, &f_lst);
	if (!data.file_lst && !data.err_lst && !f_lst)
		ft_lstpushback(&data.file_lst,
			ft_lstnew(create_tfiles(".", opendir(".")), sizeof(t_files)));
	ft_ls(&opt, &data, f_lst);
	return (0);
}
