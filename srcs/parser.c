/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 11:28:52 by ochase            #+#    #+#             */
/*   Updated: 2015/01/28 22:43:45 by ochase           ###   ########.fr       */
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
		{
			// fonction d'erreur
			exit(0);
		}
		opt->l_flag |= (*cmd == 'l');
		opt->a_flag |= (*cmd == 'a');
		opt->r_flag |= (*cmd == 'r');
		opt->t_flag |= (*cmd == 't');
		opt->re_flag |= (*cmd == 'R');
		cmd++;
	}
}

void		parser(char **argv, t_opt *opt, t_ldata *data)
{
	size_t	index;

	index = 1;
	ft_bzero(opt, sizeof(t_opt));
	ft_bzero(data, sizeof(t_data));
	while (argv[index] && argv[index][0] == '-')
		parse_cmd(argv[index++], opt);
	while (argv[index])
	{
		if (opendir(argv[index]))
		{
			ft_lstpushback(&(data->file_lst),
				ft_lstnew(argv[index], ft_strlen(argv[index])));
		}
		else
			ft_lstpushback(&(data->err_lst),
				ft_lstnew(argv[index], ft_strlen(argv[index])));
		index++;
	}
	printf("l: %d\n", opt->l_flag);
	printf("a: %d\n", opt->a_flag);
	printf("r: %d\n", opt->r_flag);
	printf("t: %d\n", opt->t_flag);
	printf("R: %d\n", opt->re_flag);
	while (data->file_lst)
	{
		printf("good: %s\n", (char*)data->file_lst->content);
		data->file_lst = data->file_lst->next;
	}
	while (data->err_lst)
	{
		printf("error: %s\n", (char*)data->err_lst->content);
		perror((char*)data->err_lst->content);
		data->err_lst = data->err_lst->next;
	}
}
