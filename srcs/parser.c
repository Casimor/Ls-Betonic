/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 11:28:52 by ochase            #+#    #+#             */
/*   Updated: 2015/01/28 20:55:52 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>
static void	parse_cmd(char *cmd, t_opt *opt)
{
	cmd++;
	while (*cmd)
	{
		if (!ft_strchr("lartR", *cmd))
			exit(0);
		opt->l_flag |= (*cmd == 'l');
		opt->a_flag |= (*cmd == 'a');
		opt->r_flag |= (*cmd == 'r');
		opt->t_flag |= (*cmd == 't');
		opt->re_flag |= (*cmd == 'R');
		cmd++;
	}
}

t_list		*parser(char **argv, t_opt *opt)
{
	t_list	*file_lst;
	t_list	*err_lst;
	size_t	index;

	file_lst = 0;
	err_lst = 0;
	index = 1;
	ft_bzero(opt, sizeof(t_opt));
	while (argv[index] && argv[index][0] == '-')
		parse_cmd(argv[index++], opt);
	while (argv[index])
	{
		if (opendir(argv[index]))
			ft_lstpushback(&file_lst,
				ft_lstnew(argv[index], ft_strlen(argv[index])));
		else
			ft_lstpushback(&err_lst,
				ft_lstnew(argv[index], ft_strlen(argv[index])));
		index++;
	}
	printf("l: %d\n", opt->l_flag);
	printf("a: %d\n", opt->a_flag);
	printf("r: %d\n", opt->r_flag);
	printf("t: %d\n", opt->t_flag);
	printf("R: %d\n", opt->re_flag);
	while (file_lst)
	{
		printf("good: %s\n", (char*)file_lst->content);
		file_lst = file_lst->next;
	}
	while (err_lst)
	{
		printf("error: %s\n", (char*)err_lst->content);
		err_lst = err_lst->next;
	}
	return (file_lst);
}
