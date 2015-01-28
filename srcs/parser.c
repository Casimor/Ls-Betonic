/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 11:28:52 by ochase            #+#    #+#             */
/*   Updated: 2015/01/28 19:13:37 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>
static void	parse_cmd(char *cmd, t_opt *opt)
{
	while (*cmd)
	{
		if (!opt->l_flag)
			opt->l_flag |= (*cmd == 'l') ? 1 : 0;
		if (!opt->a_flag)
			opt->a_flag |= (*cmd == 'a') ? 1 : 0;
		if (!opt->r_flag)
			opt->r_flag |= (*cmd == 'r') ? 1 : 0;
		if (!opt->t_flag)
			opt->t_flag |= (*cmd == 't') ? 1 : 0;
		if (!opt->re_flag)
			opt->re_flag |= (*cmd == 'R') ? 1 : 0;
		cmd++;
	}
	printf("l: %d\n", opt->l_flag);
	printf("a: %d\n", opt->a_flag);
	printf("r: %d\n", opt->r_flag);
	printf("t: %d\n", opt->t_flag);
	printf("R: %d\n", opt->re_flag);
}

t_list		*parser(char **argv, t_opt *opt)
{
	t_list	*index_lst;
	size_t	index;

	index_lst = 0;
	index = 1;
	opt->l_flag = 0;
	opt->a_flag = 0;
	opt->r_flag = 0;
	opt->t_flag = 0;
	opt->re_flag = 0;
	while (argv[index])
	{
		if (argv[index][0] == '-')
			parse_cmd(argv[index], opt);
		else
			ft_lstpushback(&index_lst, ft_lstnew(argv[index], ft_strlen(argv[index])));
		index++;
	}
	return (index_lst);
}
