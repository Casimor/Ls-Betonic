/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 15:01:57 by ochase            #+#    #+#             */
/*   Updated: 2015/01/30 15:19:15 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	t_opt	opt;
	t_ldata	data;

	(void)argc;
	parser(argv, &opt, &data);
	if (!data.file_lst)
		ft_lstpushback(&data.file_lst,
			ft_lstnew(create_tfiles(".", opendir(".")), sizeof(t_files)));
	ft_ls(&opt, &data);
	return (0);
}
